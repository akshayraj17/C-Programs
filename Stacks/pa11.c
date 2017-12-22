#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "getString.h"
#include "calc.h"
#include "string.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}
	 node_t * head = NULL; 
  	
	float a;
//	float b;
	float result;
	int count = reads(argv[1]);

 //   int flag =0;
	FILE * in;
	in = fopen(argv[1],"r");
    if( in == NULL)
	{
		return EXIT_FAILURE;;
	
	}
	if(count == 0 || count == 1)
	{
		
		return EXIT_SUCCESS;
	}
	char * c = malloc(count*sizeof(char)*256);
	while(fscanf(in,"%s",c) != EOF)
	{   // a = (float)atof(c);
		if( (*c == '+' || *c == '-' || *c == '*' || *c == '/') && c[1] == '\0')
		{
			  if(head != NULL && head -> next == NULL && (*c == '+' || *c == '-' || *c == '*' || *c == '/') )
				{
					printf("malformed");
					 free(head->next);
		 			 free(head);
					 free(c);
					 fclose(in);
					return EXIT_FAILURE;
				}
			if(*c ==  '+')
			head = calcs(head,'a');
			
			if(*c ==  '-')
		     head = calcs(head,'s');
			
			if( *c  ==  '*')
		    head = calcs(head,'m');
			
			if( *c  ==  '/')
			head = calcs(head,'d');
			
			if(head == NULL)
			{
				printf("Malformed\n");
				free(head->next);
				free(head);
				free(c);
				fclose(in);
				return EXIT_FAILURE;
			} 
			
		
		} 
		else 
		{
			a = (float)atof(c);
			head = Push(head,a);
			continue;
	 	}
		 

	//i++;
	}
/*	if(flag !=1)
	{
		printf("Malformed");
		 free(head->next);
		 free(head);
			free(c);
			fclose(in);
		return EXIT_FAILURE;
	
	}*/
	if(head != NULL && head -> next == NULL)
		 {
			result = head -> data;
			printf("%f\n",result);
			free(head->next);
			free(head);
			free(c);
			fclose(in);
			 return EXIT_SUCCESS;
		} 	

	if(head -> next != NULL)
	{
	 free(head->next);
	 free(head);
	 free(c);
	 printf("Malformed\n");
	 fclose(in);
	 return EXIT_FAILURE;
    }
 


/*	printf("%f\n", result);
	
	return EXIT_SUCCESS;
*/
}
