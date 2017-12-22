CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFLAG = -pg
GCC = gcc $(CFLAGS)  $(COVFLAGS) #$(PROFFLAG)
OBJS = pa10.o solver.o list.o mazehelper.o maze.o
GRIND = valgrind --tool=memcheck --leak-check=full -v 

all: $(OBJS)
	$(GCC) $(OBJS) -o pa10

pa10.o: pa10.c maze.h maze.c path.h solver.c solver.h list.c list.h mazehelper.c mazehelper.h 
	$(GCC) -c pa10.c

solver.o:  pa10.c maze.h maze.c path.h solver.c solver.h list.c list.h mazehelper.c mazehelper.h
	$(GCC)  -c solver.c

list.o: pa10.c maze.h maze.c path.h solver.c solver.h list.c list.h mazehelper.c mazehelper.h
	$(GCC) -c list.c

mazehelper.o:  pa10.c maze.h maze.c path.h solver.c solver.h list.c list.h mazehelper.c mazehelper.h
	$(GCC) -c mazehelper.c

maze.o:pa10.c maze.h maze.c path.h solver.c solver.h list.c list.h mazehelper.c mazehelper.h
	$(GCC) -c maze.c

test: all
	echo "testing"
	./pa10 inputs/maze1 out1
	./pa10 inputs/maze2 out2
	./pa10 inputs/maze3 out3

memory: pa10
	$(GRIND) ./pa10 inputs/maze1 out1 
	$(GRIND) ./pa10 inputs/maze2 out2
	$(GRIND) ./pa10 inputs/maze3 out3
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa10

