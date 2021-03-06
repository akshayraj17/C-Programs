#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "filterParallel.h"

int main (int argc, char ** argv) {
	if (argc != 3) {
		fprintf(stderr, "Error: wrong number of arguments\n");
		fprintf(stderr, "Usage: ./pa13 <input file> <output file>");
		exit(1);
	}
  
	FILE * orignal = fopen(argv[1],"r");
	FILE * mod = fopen(argv[2],"w");
	BoxFilter  f;
  	for(int i = 0; i < 3 ; i++){
		for (int j = 0; j < 3; j++){
			 f.filter[i][j] = 1;
		}
	}	
	f.norm = 9.0;
	
	int numThreads = 32;

	BMPImage * in = readImage(orignal);
	BMPImage * out = in; 
	apply(in,out,f,numThreads);
	writeImage(out,mod);
	freeImage(in);
	freeImage(out);
	fclose(orignal);
	fclose(mod);
 	fclose(mod);	
	return EXIT_SUCCESS;
}
