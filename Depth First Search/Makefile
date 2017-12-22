CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFLAG = -pg
GCC = gcc $(CFLAGS)  $(COVFLAGS) #$(PROFFLAG)
OBJS = pa08.o solver.o
GRIND = valgrind --tool=memcheck --leak-check=full 

all: $(OBJS)
	$(GCC) $(OBJS) maze.o path.o -o pa08

pa08.o: pa08.c maze.h path.h solver.c solver.h
	$(GCC) -c pa08.c

solver.o: pa08.c maze.h path.h solver.c solver.h
	$(GCC)  -c solver.c

test: pa08
	echo "testing"
	./pa08 inputs/maze1  
	./pa08 inputs/maze2 
	./pa08 inputs/maze3
	./pa08 inputs/maze4
	./pa08 inputs/maze5

memory: pa08
	$(GRIND) ./pa08 inputs/maze1 
	$(GRIND) ./pa08 inputs/maze2
	$(GRIND) ./pa08 inputs/maze3	
	$(GRIND) ./pa08 inputs/maze4
	$(GRIND) ./pa08 inputs/maze5
clean:
	/bin/rm -f solver.o pa08.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa08

