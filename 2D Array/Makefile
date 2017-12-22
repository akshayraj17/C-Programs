CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code
COVFLAGS = -fpofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) # $(COVFLAGS) 
OBJS = pa07.0 maze.o path.o
GRIND = valgrind --tool=memcheck --leak-check=full 

all: pa07

pa07: pa07.o maze.o path.o
	$(GCC) pa07.o maze.o path.o -o pa07

maze.o: maze.c maze.h
	$(GCC) maze.c -c

path.o: path.c path.h maze.h
	$(GCC) path.c -c

test: pa07
	echo "testing"
	./pa07 inputs/maze1 inputs/path1 
	./pa07 inputs/maze1 inputs/path1-bad1
	./pa07 inputs/maze1 inputs/path1-bad2
memory: pa07
	$(GRIND) ./pa07 inputs/maze1 inputs/path1
	$(GRIND) ./pa07 inputs/maze1 inputs/path1-bad1
	$(GRIND) ./pa07 inputs/maze1 inputs/path1-bad2

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa07.prof
	/bin/rm -f pa07

