CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFLAG = -pg
GCC = gcc $(CFLAGS)  $(COVFLAGS) #$(PROFFLAG)
OBJS = pa12.o expressionTree.o tree.o scanner.o
GRIND = valgrind --tool=memcheck --leak-check=full -v 

all: $(OBJS)
	$(GCC) $(OBJS) -o pa12

pa12.o: pa12.c expressionTree.c tree.c scanner.c tree.h expressionTree.h scanner.h
	$(GCC) -c pa12.c

tree.o: pa12.c expressionTree.c tree.c scanner.c tree.h expressionTree.h scanner.h
	$(GCC) -c tree.c

expressionTree.o: pa12.c expressionTree.c tree.c scanner.c tree.h expressionTree.h scanner.h
	$(GCC) -c expressionTree.c

scanner.o: pa12.c expressionTree.c tree.c scanner.c tree.h expressionTree.h scanner.h
	$(GCC) -c scanner.c


test: all
	echo "testing"
	./pa12 inputs/test1 out1
	./pa12 inputs/test2 out2
	./pa12 inputs/test3 out3
	./pa12 inputs/test4 out4

memory: pa12
	$(GRIND) ./pa12 inputs/test1 out1 
	$(GRIND) ./pa12 inputs/test2 out2
	$(GRIND) ./pa12 inputs/test3 out3
	$(GRIND) ./pa12 inputs/test4 out4

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa12
