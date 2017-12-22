#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "filter.h"

int main (int argc, char ** argv) {
	if (argc != 4) {
		fprintf(stderr, "Error: wrong number of arguments\n");
		fprintf(stderr, "Usage: ./pa13 <input file> <output file>");
		exit(1);
	}
  
	FILE * orignal = fopen(argv[1],"r");
	FILE * filter = fopen(argv[3],"r");
	FILE * mod_img = fopen(argv[2],"w");
	BoxFilter * peace = readFilter(filter);
  for(int i = 0; i < 3 ; i++){
		for (int j = 0; j < 3; j++){
			printf("%d\n", peace->filter[i][j]);
		}
	}	

	BMPImage * img = readImage(orignal);
	BMPImage * mod =  apply(img,*peace);
	writeImage(mod,mod_img);
	freeImage(img);
	freeImage(mod);
	free(filter);
	fclose(orignal);
	fclose(mod_img);
 	fclose(mod_img);	
	return EXIT_SUCCESS;
}
