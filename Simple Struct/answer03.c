#include "pa03.h"
double integrate1(Range rng)
{
	
	
	int i;
	double total;
	total=0;
	for(i = 0; i < rng.intervals; i++)
	{
	  total = total + func((rng.lowerlimit) + (i) * (((rng.upperlimit) - (rng.lowerlimit)) / (rng.intervals)));
	  
	 }
	
	total = (((rng.upperlimit) - (rng.lowerlimit)) / (rng.intervals)) * total;	
	return total;
	
	//Perform numerical integration of the function func(x)
	//INPUT: Range rng -- the lower and upper limits of the integration
	//                    and the number of intervals to integrate over
	//OUTPUT: Return the result of the integration

}

void integrate2(RangeAnswer * rngans)
{
	 
     double result;
     result = integrate1(rngans -> rng);
	 rngans -> answer = result;

	
	//Perform numerical integration of the function func(x)
	//INPUT: RangeAnswer * rngans 
	//              -- the lower and upper limits of the integration
	//                 and the number of intervals to integrate over
	//OUTPUT: The result of the integration should be placed in rngans->answer

	//You should try to call integrate1 when implementing integrate2
}
