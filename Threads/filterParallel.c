#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "filterParallel.h"

void   applyThread(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int tid, int numThreads) {
	
	//FILL IN. This is the work that thread #tid should do
	//You may find it useful to know the number of threads (numThreads) to
	//figure out what to do.
     BoxFilter b;	
	int i,j;
	//create box blur 2D array
	for( i=0; i < 3; i++)
	{
		for( j=0; j<3; j++)
		{
			b.filter[i][j] = f.filter[i][j];
		
		}
	
	}
  
	b.norm = f.norm;
	
		//blurred lines
		int left,right,top,bottom;
		int totalb,totala,totalr,totalg;

	int interval_h = (imageIn -> norm_height + numThreads - 1)/numThreads;
	int h_low = (tid*interval_h);
	int h_high = h_low + interval_h;
	if( h_high > imageIn -> norm_height){ h_high = imageIn -> norm_height;}
/*	int interval_w = (imageIn -> header.width_px + numThreads - 1)/numThreads;
	int w_low = (tid*interval_w);
	int w_high = w_low + interval_w;
	if( w_high > imageIn -> header.width_px){ w_high = imageIn -> header.width_px;}
*/
	for( i=h_low; i < h_high-1; i++)
	{
		for(j = 0; j < imageIn -> header.width_px-1; j++)
		{	
		 	totalr = 0;
			totalb = 0;
			totalg = 0;
			totala = 0;
			left = j-1;
		 	right = j+1;
		 	top = i-1;
		 	bottom = i+1;
			 
			
			 	if( left < 0)
				{
			 		left = j;
			 	}
			 
				if( top < h_low)
				{
					top = i;
				}
			 
			 
			  if( bottom >= h_high)
			  {
			      bottom  = i;
			  }
			 
			 if(  right >= imageIn-> header.width_px)
			 {
			 	 right = j;
			 }
			 

				totalb = (imageIn -> pixels[top][left].blue)*( b.filter[0][0]) + (imageIn-> pixels[top][j].blue)*(b.filter[0][1]) +
						 (imageIn -> pixels[i][left].blue)*( b.filter[1][0]) + (imageIn-> pixels[i][j].blue)*(b.filter[1][1]) +
						 (imageIn -> pixels[i][right].blue)*( b.filter[1][2]) + (imageIn -> pixels[bottom][left].blue)*(b.filter[2][0]) +
						 (imageIn -> pixels[bottom][j].blue)*( b.filter[2][1]) + (imageIn -> pixels[bottom][right].blue)*(b.filter[2][2]) +
						 (imageIn -> pixels[top][right].blue)*( b.filter[0][2]);
				
				totalr = (imageIn -> pixels[top][left].red)*( b.filter[0][0]) + (imageIn -> pixels[top][j].red)*(b.filter[0][1]) +
						 (imageIn -> pixels[i][left].red)*( b.filter[1][0]) + (imageIn -> pixels[i][j].red)*(b.filter[1][1]) +
						 (imageIn -> pixels[i][right].red)*( b.filter[1][2]) + (imageIn -> pixels[bottom][left].red)*(b.filter[2][0]) +
						 (imageIn -> pixels[bottom][j].red)*( b.filter[2][1]) + (imageIn -> pixels[bottom][right].red)*(b.filter[2][2]) +
						 (imageIn -> pixels[top][right].red)*( b.filter[0][2]);

				totalg = (imageIn -> pixels[top][left].green)*( b.filter[0][0]) + (imageIn -> pixels[top][j].green)*(b.filter[0][1]) +
						 (imageIn -> pixels[i][left].green)*( b.filter[1][0]) + (imageIn -> pixels[i][j].green)*(b.filter[1][1]) +
						 (imageIn -> pixels[i][right].green)*( b.filter[1][2]) + (imageIn -> pixels[bottom][left].green)*(b.filter[2][0]) +
						 (imageIn -> pixels[bottom][j].green)*( b.filter[2][1]) + (imageIn -> pixels[bottom][right].green)*(b.filter[2][2]) +
						 (imageIn -> pixels[top][right].green)*( b.filter[0][2]);
				
				totala = (imageIn -> pixels[top][left].alpha)*( b.filter[0][0]) + (imageIn -> pixels[top][j].alpha)*(b.filter[0][1]) +
						 (imageIn -> pixels[i][left].alpha)*( b.filter[1][0]) + (imageIn -> pixels[i][j].alpha)*(b.filter[1][1]) +
						 (imageIn -> pixels[i][right].alpha)*( b.filter[1][2]) + (imageIn -> pixels[bottom][left].alpha)*(b.filter[2][0]) +
						 (imageIn -> pixels[bottom][j].alpha)*( b.filter[2][1]) + (imageIn -> pixels[bottom][right].alpha)*(b.filter[2][2]) +
						 (imageIn -> pixels[top][right].alpha)*( b.filter[0][2]); 
				          
						 totalb = totalb/b.norm;
						 totalr = totalr/b.norm;
						 totalg = totalg/b.norm;
						 totala = totala/b.norm;
  
						if( totala > 255)
						  totala = 255;
						  if(totala < 0)
						   totala = 0;
						  if( totalb > 255)
						  totalb = 255;
						  if(totalb < 0)
						   totalb = 0;
						  if( totalg > 255)
						  totalg = 255;
						  if(totalg < 0)
						   totalg = 0;
						  if( totalr > 255)
						  totalr = 255;
						  if(totalr < 0)
						   totalr = 0;



						 imageOut -> pixels[i][j].blue = totalb;
						 imageOut -> pixels[i][j].red = totalr;
						 imageOut -> pixels[i][j].green = totalg;
						 imageOut -> pixels[i][j].alpha = totala;
							
						 
				 
		}		
			
	} // end of outer for loop
   
 return;

}

void * applyThreadWrapper(void * args) {
	ApplyArgs * applyArgs = (ApplyArgs *) args;
	fprintf(stdout, "calling thread %d\n", applyArgs->tid);
	
	applyThread(applyArgs->in, applyArgs->out, applyArgs->filter, applyArgs->tid, applyArgs->numThreads);
	
	fprintf(stdout, "finished with thread %d\n", applyArgs->tid);
	
	return NULL;
}

void apply(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int numThreads) {

	//FILL IN:
	
	//1. create numThreads threads, that each call applyThreadWrapper
	//2. wait for all threads to finish
	//3. clean up any memory allocation you did.
	
	pthread_t * threads = malloc(sizeof(pthread_t) * numThreads);

	ApplyArgs * args = malloc( sizeof(ApplyArgs) * numThreads);

	for( int i =0 ; i < numThreads; i++ ) 
	{
		args[i].tid = i;
		args[i].numThreads = numThreads;
		args[i].in = imageIn;
		args[i].out = imageOut;
		args[i].filter = f;
	}
	for ( int i =0; i < numThreads; i++)
	{
		pthread_create(&threads[i],NULL,applyThreadWrapper,&args[i]);
	}
	for( int i =0; i < numThreads; i++)
	{
		pthread_join(threads[i],NULL);
	}
	
	free(args);

	free(threads);


	 return;


}
