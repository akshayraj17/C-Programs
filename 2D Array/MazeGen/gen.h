typedef struct {
  int r;
  int c;
} Coors;

char * * memAlloc(int, int);
void genCoors(Coors *, Coors *, int, int);
void printRandom(FILE * file);
void allPrint(FILE*, FILE*, FILE*, FILE*, char);
char getRandDir();
void addScrewup(FILE*,int*);
void addBackForth(FILE*, char);
void freeMatrix(char * * matrix, int);
