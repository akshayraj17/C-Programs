#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#ifndef READIMAGE_OFF
BMPImage * readImage(FILE * fp) {

	size_t read;
	int ind1;
	int ind2;
	BMPImage * p = malloc(sizeof(BMPImage));
	size_t read1;
	 read = fread(&(p->header),sizeof(BMPHeader),1,fp);
	if(read != 1)
	{
		exit(1);
	}

	p-> norm_height = abs(p->header.height_px);
	p -> pixels = malloc(p->norm_height * sizeof(Pixel *));
	for(ind1 = 0; ind1 < p->norm_height; ind1++)
	{
		p -> pixels[ind1] = malloc(p->header.width_px * sizeof(Pixel));
	}
	
	for( ind1 = 0; ind1 < p->norm_height; ind1++ )
	{
		for(ind2 = 0; ind2 < p->header.width_px; ind2++)
		{
			read1 = fread(&(p->pixels[ind1][ind2]),sizeof(Pixel),1,fp);
				if(read1 != 1)
				exit(1);
		}
	
	}
  
  

	
	return p;
}

void freeImage(BMPImage * image) {
 int i;
 for(i = 0; i< image -> norm_height;i++)
 	free(image -> pixels[i]);

 free(image -> pixels);
 free(image);
}
#endif

#ifndef WRITEIMAGE_OFF
	
void writeImage(BMPImage * image, FILE * fp) {
	
	
	size_t read;

	read = fwrite(&image -> header,sizeof(BMPHeader),1,fp);
	if(read != 1)
	{
		exit(1);
	}

	int ind1;
	int ind2;
	int read1;	
	
	for( ind1 = 0; ind1 < image->norm_height; ind1++ )
	{
		for(ind2 = 0; ind2 < image->header.width_px; ind2++)
		{
			read1 = fwrite(&(image->pixels[ind1][ind2]),sizeof(Pixel),1,fp);
			 if(read1 != 1)
				exit(1);
		}
	}
 
 return;

}
#endif
