#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF
Maze * readMaze(char * mazeFilename)
{

	FILE * fp1;
	Maze * m = malloc(sizeof(Maze));
	fp1 = fopen(mazeFilename,"r");
   
	if(fp1 == NULL)
	{
	  return m;
	}
	
    
	fscanf(fp1,"%d %d\n" ,&(m->height),&(m->width));
       m->maze = malloc(((*m).height)*sizeof(MazeSquare*));
	int ind1;

	for( ind1 =0; ind1<(m->height);ind1++)
	{
	  m->maze[ind1] = malloc((m->width)*sizeof(MazeSquare));
	}
    int ind2,ind3;
    for(ind2 =0;ind2<m->height;ind2++)
	{
	 for(ind3=0;ind3<m->width;ind3++)
	 {
	   char ch = fgetc(fp1);
	   if (ch== '\n')
	     ch = fgetc(fp1);
	   m->maze[ind2][ind3].type = ch;
      
	  if(m->maze[ind2][ind3].type == (SquareType)START)
	  {
	    m->start.xpos = ind2;
		m->start.ypos = ind3;
	  }
	  if(m->maze[ind2][ind3].type == (SquareType)END)
	  {
	    m->end.xpos = ind2;
		m->end.ypos = ind3;
	  }



	 }
	 
	}
	fclose(fp1);
	return m;

}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {
 int i;
for(i =0; i< (m -> height);i++)

 { free(m->maze[i]);}
 free(m->maze);
 

}
#endif //#ifndef FREEMAZE_OFF
