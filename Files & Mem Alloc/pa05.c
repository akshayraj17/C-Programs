// You must modify this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

// --------------------------------------------------------------
int main(int argc, char * * argv)
{
  // argv[1]: input file name
  // argv[2]: output file name, sorted by ID
  // argv[3]: output file name, sorted by first name
  // argv[4]: output file name, sorted by last name
  if (argc < 5)
    {
      return EXIT_FAILURE;
    }
  // create the necessary variables
  FILE *fp1 = fopen(argv[1],"r");
  if(fp1 == NULL){return EXIT_FAILURE;}
  int numelem;
  Student *sp1;
  // read students from the input file
  // return EXIT_FAILURE if reading fails
  int check1 =  StudentRead(argv[1], &sp1, &numelem);
  if(check1 !=1)
   return EXIT_FAILURE;

 
  // sort the students by IDs
  StudentSortbyID(sp1,numelem);
    

  
  // write the result to the output (name is argv[2])
  // return EXIT_FAILURE if writing fails
  
   StudentWrite(argv[2], sp1, numelem);



  // sort the students by first names
  
   StudentSortbyFirstName(sp1,numelem);



  // write the result to the output (name is argv[3])
  // return EXIT_FAILURE if writing fails

  int check2 = StudentWrite(argv[3], sp1, numelem);
  if(check2!=1)
  return EXIT_FAILURE;

  // sort the students by last names
  
   StudentSortbyLastName(sp1,numelem);



  // write the result to the output (name is argv[4])
  // return EXIT_FAILURE if writing fails


 int check3 =  StudentWrite(argv[4],sp1,numelem);
 if(check3!=1)
 return EXIT_FAILURE;
 fclose(fp1);

  // release allocated memory

  free(sp1);



  return EXIT_SUCCESS;
}
