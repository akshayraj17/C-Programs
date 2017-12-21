// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constant.h"


void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  for (int ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // open the file to read
  FILE * fp1;
  fp1 = fopen(filename,"r+");

  // if fopen fails, return false
  // do not use fclose since fopen already fails

  if(fp1 == NULL)
   {
     return false;
   }

  // count the number of lines to determine the number of students
   int line = 0;
   int c1;
   while((c1 = fgetc(fp1)) != EOF)
   {
     if( c1 == '\n')
	 line++;
//   fp1++;	
   }
   *numelem = line; 

  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails
  
  int check1 = fseek(fp1,0,SEEK_SET);
  if(check1 == -1)
   return false;

  // allocate memory for the data

   *stu  = malloc(sizeof(Student) * line);
   

  // check whether memory allocation fails

   if(stu == NULL)
    return false;

  // read the data from the file and store the data in the allocated memory
    	int n;
   for(n=0;n<line;n++)
   { 
	 
	  fscanf(fp1,"%d",&((*stu)[n].ID));
	  fscanf(fp1,"%s",(*stu)[n].firstname);
	  fscanf(fp1,"%s",(*stu)[n].lastname);
     
	
	} 
  

  // close the file

  fclose(fp1);

  


  return true;
}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
  // open the file to write 

  FILE * fp2;
  fp2 = fopen(filename,"w");


  // if fopen fails, return false
  // do not use fclose since fopen already fails

  if (fp2 == NULL)
   return false;

  // write the students to the output file
   int n1;
  for(n1=0;n1<numelem;n1++)
  {
    fprintf(fp2,"%d ",stu[n1].ID); 
	fprintf(fp2,"%s ",stu[n1].firstname);
	fprintf(fp2,"%s\n",stu[n1].lastname);
	
  }

 fclose(fp2);

 return true;

}
#endif 
int cmpstring1(const void *arg1, const void *arg2)
{
 const Student *ptr1 = (const Student *) arg1;
 const Student *ptr2 = (const Student *) arg2;
 const char * str1 = ptr1->firstname;
 const char * str2 = ptr2->firstname;
 return strcmp(str1,str2);
}
int cmpstring2(const void *arg1, const void *arg2)
{
 const Student *ptr1 = (const Student *) arg1;
 const Student *ptr2 = (const Student *) arg2;
 const char * str1 = ptr1->lastname;
 const char * str2 = ptr2->lastname;
 return strcmp(str1,str2);
}

int cmpint(const void * arg1, const void * arg2)
{
 const Student * ptr1 = (const Student *) arg1;
 const Student * ptr2 = (const Student *) arg2;
 int val1 = ptr1->ID;
 int val2 = ptr2->ID;
 if(val1 < val2){ return -1;}
 if(val1 == val2){return 0;}
 return 1;
}

#ifdef TEST_SORTID
void StudentSortbyID(Student * stu, int numelem)
{
  qsort(stu,numelem,sizeof(Student),cmpint);


}
#endif


#ifdef TEST_SORTFIRSTNAME
void StudentSortbyFirstName(Student * stu, int numelem)
{
   qsort(stu,numelem,sizeof(Student),cmpstring1);
}
#endif

#ifdef TEST_SORTLASTNAME

void StudentSortbyLastName(Student * stu, int numelem)
{
 qsort(stu,numelem,sizeof(Student),cmpstring2);
}
#endif
