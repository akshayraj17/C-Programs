#include <stdio.h>
#include <stdlib.h>
#include "getString.h"

int reads(char * infile)
{
	FILE * inf;
	inf = fopen(infile,"r");
	if(inf == NULL)
	  return 0;
	
	int count1 = 0;
	char c;
	while((c = fgetc(inf)) != EOF)
	{
		if(c == ' ')
		continue;
		if(c == '\0')
		continue;
		count1++;
	}
fclose(inf);
return count1;	

}

















