#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() {
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
}

void freePaths(PathLL * p) {
	freeNode(p->head);
	free(p);
}

PathNode * buildNode(char * path) {
	PathNode * temp;
	temp = malloc(sizeof(PathNode));
	int x, count;
	count =0;
	for( x = 0; path[x] != '\0';x++)
	{
	  count ++;
	}
	temp -> path = malloc( sizeof(char)*(count +1));
	strcpy(temp->path,path);
	return temp;
	
	//WARNING: don't forget to use strcpy to copy path into the
	//new node. Don't just set them equal, otherwise if the input path changes
	//the node will have the wrong path.
}

void freeNode(PathNode * p) {
	free(p->path);
	free(p);
}

bool addNode(PathLL * paths, char * path) {
    // initial test
 		if(strlen(path) == 0)
		return false;
		
   //declarations
	   int turnp1 = 0;
	   int turnp2 = 0;
	   	   int i = 0;
	   PathNode * temp = buildNode(path);

 	//empty linked list case

/*	 if ( paths -> head -> next == NULL) 
 	 {
	  	PathNode * node5 = buildNode(path);
		paths -> head -> next = node5;
		node5 -> next = NULL;
		return true;
	 }
	 */
	PathNode * prev = NULL;
    PathNode * curr = paths -> head;
    if ( paths -> head == NULL )
	 {  
        paths -> head  = temp;
		paths -> head -> next = NULL;
		return true;
		//freeNode(temp);
	 }
	while(  curr != NULL)
	 {  if( prev == NULL)
	 	break;
	  	//length
	    if( strlen(path) < strlen(curr -> path)) //&& strlen(path) > strlen(prev->path) )
		{   
		     PathNode * node1 = buildNode(path);	
			 prev -> next = node1;
			 node1 -> next = curr;	
			  prev = curr;
				curr = curr -> next;
			 return true;
		}
		//turns
 		else if( strlen(path) == strlen( curr -> path))
		{ 
		   for(i=1; path[i] != '\0' ; i++)
		   {
		     if(path[i-1] != path[i])
			 turnp1 ++;
		   }
		   for( i =1; curr -> path[i] != '\0';i++ )
		   {
		     if( curr -> path[i-1] != curr -> path[i])
			 turnp2 ++;
		   }
		  
	       if(turnp1 < turnp2)
		   {
		   		 PathNode * node2 = buildNode(path);
				 prev -> next = node2;
			   	 node2 -> next = curr;
				 prev = curr;
				curr = curr -> next;

				 return true;
		   }
		   else
		   {
		   		PathNode * node6 = buildNode(path);
		   		node6 -> next = curr -> next;
		   		curr -> next = node6;
				prev = curr;
				curr = curr -> next;

				return true;
		   }
		   		   
		
		}
        // alphabetic
  		else if(strcmp(path, curr -> path) <= 0 && strlen(path) == strlen( curr -> path) && turnp1 == turnp2 )
			{   
				PathNode * node4 = buildNode(path);
				prev -> next = node4;
				node4 -> next = curr;
				prev = curr;
				curr = curr -> next;
				return true;
			}
		
		else
	 	{ 
 		prev = curr;
		curr  = curr -> next;
		}
	}	
       
	   
	        if( (strlen(path) < strlen(curr -> path)))
			{
		 		PathNode * node7 = buildNode(path);
   		 		node7 -> next = curr;
		 		node7  =  curr;
				prev = curr;
				curr = curr -> next;
				return true;
		 	}
			else if( turnp1 < turnp2 && strlen(path) == strlen(curr -> path))
			{   
				PathNode * node7 = buildNode(path);
   		 		node7 -> next = curr;
		 		node7  =  curr;
				prev = curr;
				curr = curr -> next;
				return true;
			}
			else if(strcmp(path,curr -> path) <= 0 && strlen(path) == strlen(curr -> path) && turnp2 > turnp1)
			{
				PathNode * node7 = buildNode(path);
   		 		node7 -> next = curr;
		 		node7  =  curr;
				prev = curr;
				curr = curr -> next;
				return true;
			}

		 	else
		 	{
		 		PathNode * node8 = buildNode(path);
		    	node8 -> next = curr -> next;
		 		curr -> next = node8;
				prev = curr;
				curr = curr -> next;
				return true;
		 	}

 

}

bool removeNode(PathLL * paths, char * path) {
 
 	if(containsNode(paths,path) == 0)
		return false;
	PathNode * temp;
	PathNode *curr = paths -> head;

	while( strcmp(path,curr -> next -> path) != 0)
	{
	 	 	curr = curr -> next;
	}
	
	temp = curr -> next;
	curr -> next = temp -> next -> next;
	freeNode(temp);
	
	return true;
 
}

bool containsNode(PathLL * paths, char * path) {
	
	if(paths -> head == NULL)
     return false;

	PathNode * curr = paths -> head;

	while( curr != NULL)
	{
	 if(strcmp(path, curr -> path) == 0) 
	 { 
	  return true;
	 }
	curr = curr -> next;
	}
	return false;
   


}

void printPaths(PathLL * paths, FILE * fptr) {
	PathNode * curr = paths->head;
	int i = 0;
	while (curr != NULL) {
		fprintf(fptr, "Path %2d: %s\n", i, curr->path);
		i++;
		curr = curr->next;
	}
}
