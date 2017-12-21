#include <stdio.h>
#include <stdbool.h>
#include "pa04.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable partial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
   int i;
   double total;
   total =0;

   for(i = 0;i < intrg -> intervals; i++)
   {
     total = total + intrg -> func((intrg -> lowerlimit) + (i) * (((intrg -> upperlimit) - (intrg -> lowerlimit)) / (intrg -> intervals)));
   
   }

   total = (((intrg -> upperlimit) -(intrg -> lowerlimit)) / (intrg -> intervals)) * total;

   intrg -> answer = total; 

}
 #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable partial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading
   FILE * inf;
   inf = fopen(infilename,"r");
   if(inf == NULL)
    return false;
 // if fopen fails, return false



  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  Integration intrg;
  int check1  = fscanf(inf,"%lf\n",&intrg.lowerlimit );
   if (check1 !=1)
	{  
	   fclose(inf);
	   return false;
    }
  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  int check2 = fscanf(inf,"%lf\n", &intrg.upperlimit);
   if(check2 != 1)
   {
    fclose(inf);
    return false;
   }	

  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  int check3 = fscanf(inf,"%d\n",&intrg.intervals);
   if(check3 !=1 )
  {
   fclose(inf);
   return false;
  }
  // close the input file
   FILE * outf;
    outf = fopen(outfilename,"w");

  // open the output file for writing
  // if fopen fails, return false


   if(outf == NULL)
   return false;





  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5

  funcptr funcs[] = {func1,func2,func3,func4,func5};



  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf

   
    double  temp[5];
   for(int ind = 0; ind < 5 ; ind++)
   {
   
     intrg.func = funcs[ind] ;
	 integrate(&intrg);
	 temp[ind] = intrg.answer;
     fprintf(outf,"%lf\n",temp[ind]); 
   }



  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false

  int j;
  for(j=0; j<5;j++)
  {
   double check = fprintf(outf, "%lf",temp[j]);
   if(check<1)
   {
     fclose(outf);
	 return false;
   }
  
  }





  // after going through all functions in funcs
  // close the output file



  fclose(outf);



  // if the function reaches here, return true


   return true;


}
#endif // RUN_INTEGRATE
