#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"

char * solveMaze(Maze * m) {
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {


     bool check; 
	  
      if( (curpos.xpos<0 || curpos.xpos >= m->width) || (curpos.ypos<0 || curpos.ypos >= m->height))
          return false;
	  if(m->maze[curpos.ypos][curpos.xpos].visited == true)
	   return false;

	  if(((*m).maze[curpos.ypos][curpos.xpos].type) == (SquareType)WALL )
	    return false;
        if(((*m).maze[curpos.ypos][curpos.xpos].type) == (SquareType)END )
       { path[step] = '\0';
	     return true;
		
    	}
		
     if((((*m).maze[curpos.ypos][curpos.xpos].type) == (SquareType)SPACE ) || (((*m).maze[curpos.ypos][curpos.xpos].type) == (SquareType)START))
	
	  {  m->maze[curpos.ypos][curpos.xpos].visited = true;
	  	curpos.ypos = curpos.ypos -1;
	    check = depthFirstSolve(m,curpos,path,step+1);
	    if(check == false)
		{
		  curpos.ypos = curpos.ypos + 2;
		  
		  check = depthFirstSolve(m,curpos,path,step+1);
		  if (check == false)
		  {
		    curpos.ypos = curpos.ypos -1;
			curpos.xpos = curpos.xpos -1;
			check = depthFirstSolve(m,curpos,path,step+1);
			if(check == false)
			{
			  curpos.xpos = curpos.xpos +2;
			  check = depthFirstSolve(m,curpos,path,step+1);
			  curpos.xpos = curpos.xpos - 1;
			 if(check == false)
			{  
			  
			  return false;
			}
			else
			 {
			 path[step] = 'e';
			 return true;
			 }
			}
			else
			{
			  path[step] = 'w';
			  return true;
			}
		  
		  }
		  else 
		  {
		   path[step] = 's';
		   return true;
		  }

		
		}
	  else
	  {
	   path[step] = 'n'; 
	    return true;
	  }
	 }
	  
	  
	  
	  
	  
	  
	  
		
		
		return false;
}
