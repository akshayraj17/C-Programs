#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "maze.h"

#ifndef READPATH_OFF
char * readPath(char * pathFilename)
{
  FILE * fp;
  char ch;
  int size = 1;
  fp = fopen(pathFilename,"r");
  while((ch = fgetc(fp)) != EOF)
  {
    size++;
  }
  char * path = malloc(size*(sizeof(char)));
 
  fclose(fp);
  FILE * fp1;
  fp1 = fopen(pathFilename,"r+");
  char ch1;
  int i =0;
  while((ch1 = fgetc(fp1)) != EOF)
  {
    path[i] = ch1;
	i++;
  }



 fclose(fp1);

  return path;

}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path)
{ 
  int x,y;
   x = m->start.xpos;
   y = m->start.ypos;
  int n;
 
    for(n=0; path[n] != '\0'; n++)
  {
      if(path[n] == (PathType)NORTH)
      {  
	   x  = x -1;
	   if(path[n+1] == (PathType)SOUTH)
	    return false;
	  }
      if(path[n] == (PathType)SOUTH)
      {
        x = x + 1;
		if(path[n+1] == (PathType)NORTH)
		return false;
      }
	  if(path[n] == (PathType)EAST)
      {
	   y = y + 1;
	   if(path[n+1] == (PathType)WEST)
	   return false;
      } 
	  if(path[n] == (PathType)WEST)
      {  
       y = y - 1;
	   if(path[n+1] == (PathType)EAST)
	   return false;
      }
      if( (x<0 || x>= m->height) || (y<0 || y >= m->width))
          return false;
	 

	  if(((*m).maze[x][y].type) == (SquareType)WALL )
	    return false;

      if(((*m).maze[x][y].type) == (SquareType)SPACE )
	   continue;
	 
      if(((*m).maze[x][y].type) == (SquareType)END )
        return true;	
	  
  }
  



 return false;

 }
#endif //#ifndef CHECKPATH_OFF
