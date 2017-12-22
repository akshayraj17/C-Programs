#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"gen.h"

void printPath(char * fileName) {

  FILE * file = fopen(fileName, "r");

  char c;
  int code;

  printf("%s: ", fileName);

  do {
    code = fscanf(file, "%c", &c);
    printf("%c", c);
  }while(code != EOF);
  
  printf("\n");
  fclose(file);
}

int main(int argc, char ** argv) {

  // Set Rand Seed
  srand(time(NULL));

  // Set Rows / Cols
  int rows = (rand() % 25) + 5;
  int cols = rows;//(rand() % 15) + 5;

  printf("\nStarted Generation...\n");

  // Allocate Space for Maze
  char * * matrix = memAlloc(rows, cols);

  // Init Coordinates / Final Cooridnates
  Coors init, final;
  
  // Generate Init / Final Positions
  genCoors(&init, &final, rows, cols);

  // Set the Start and End Position
  matrix[init.r][init.c] = 's';
  matrix[final.r][final.c] = 'e';
  
  // Files
  FILE * file = fopen("maze", "w");
  
  FILE * path = fopen("path_good1", "w");
  FILE * path2 = fopen("path_good2", "w");
  FILE * path3 = fopen("path_bad1", "w");
  FILE * path4 = fopen("path_bad2", "w");

  // Prints Rows & Cols to Maze
  fprintf(file, "%d %d\n", cols, rows);

  int horDir = init.c < final.c ? 1 : -1;
  int verDir = init.r < final.r ? 1 : -1;
  
  // Acts like a bool
  int screwup = 0;
  int backForth = 0;

  while(init.c != final.c || init.r != final.r) {
    int where = rand() % 2;

    if(where) {
      if(init.c != final.c) {
	init.c += horDir;

        allPrint(path, path2, path3, path4, horDir == 1 ? 'e' : 'w');

	if(init.c == final.c && init.r == final.r) {
          break;
        }

	if(!backForth && rand() % 5 == 0) {
	  addBackForth(path4, horDir == 1 ? 'e' : 'w');
	  backForth = 1;
	}

	matrix[init.r][init.c] = '.';
      }
    } 

    if(!where){
      if(init.r != final.r) {
        init.r += verDir;     

        allPrint(path, path2, path3, path4, verDir == 1 ? 's' : 'n');

	if(init.c == final.c && init.r == final.r) {
	  break;
	}

	if(!backForth && rand() % 5 == 0) {
	  addBackForth(path4, verDir == 1 ? 's' : 'n');
	  backForth = 1;
	}
       
        matrix[init.r][init.c] = '.';
      }
    }

    addScrewup(path3, &screwup);
  }

  // Print More Chars
  printRandom(path2);
  printf("\n");

  // Print out the matrix
  int i, j;
  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      fprintf(file, "%c", matrix[i][j]);
      printf("%c", matrix[i][j]);
    }
    fprintf(file, "\n");
    printf("\n");
  }

  printf("\n");

  // Close Files
  fclose(path);
  fclose(path2);
  fclose(path3);
  fclose(path4);

  fclose(file);

  freeMatrix(matrix, rows);
  
  // Print out each path
  printPath("path_good1");
  printPath("path_good2");
  printPath("path_bad1");
  printPath("path_bad2");

  printf("\n");
}

void freeMatrix(char * * matrix, int rows) {
 
  int i;
  for(i = 0; i < rows; i++) {
    free(matrix[i]);
  }

  free(matrix);
}

char * * memAlloc(int rows, int cols) {

  char * * matrix = malloc(sizeof(char *) * rows);

  int i, j;
  for(i = 0; i < rows; i++) {
    matrix[i] = malloc(sizeof(char) * cols);
  }

  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      matrix[i][j] = '#';
    }
  }

  return matrix;
}

void genCoors(Coors * init, Coors * final, int rows, int cols) {
  int top = rand() % 2;
  int left = rand() % 2;

  init -> r = (rand() % (rows / 4)) + (top ? 0 : (rows * 3 / 4));
  init -> c = (rand() % (cols / 4)) + (left ? 0 : (cols * 3 / 4));

  final -> r = (rand() % (rows / 4)) + (!top ? 0 : (rows * 3 / 4));
  final -> c = (rand() % (cols / 4)) + (!left ? 0 : (cols * 3 / 4));
}

void allPrint(FILE * file, FILE * file2, FILE * file3, FILE * file4, char c) {
  fprintf(file, "%c", c);
  fprintf(file2, "%c", c);
  fprintf(file3, "%c", c);
  fprintf(file4, "%c", c);
}

void printRandom(FILE * file) {

  int cnt = rand() % 3 + 1;
  int i;
  for(i = 0; i < cnt; i++) {
    char c = getRandDir();
    fprintf(file, "%c", c);
  }
}

char getRandDir() {
  int dir = rand() % 4;
  char c;

  switch(dir) {
  case 0:
    c = 'n';
    break;
  case 1:
    c = 's';
    break;
  case 2:
    c = 'w';
    break;
  case 3:
    c = 'e';
  }

  return c;
}

void addScrewup(FILE * bad1, int * screwup) {
  if(*screwup) {
    return;
  }

  fprintf(bad1, "%c", getRandDir());

  int setScrewup = rand() % 3;
 
  if(!setScrewup) {
    *screwup = 1;
  }
}

void addBackForth(FILE * bad, char lastChar) {

  if(lastChar == 'e') {
    fprintf(bad, "%c", 'w');
  } else if(lastChar == 'w') {
    fprintf(bad, "%c", 'e');
  } else if(lastChar == 'n') {
    fprintf(bad, "%c", 's');
  } else if(lastChar == 's') {
    fprintf(bad, "%c", 'n');
  }

  fprintf(bad, "%c", lastChar);
}
