CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code
PROFLAG = -pg
COFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)  #$(PROFFLAG)
OBJS = pa11.o linkedlist.o calc.o getString.o 
GRIND = valgrind --tool=memcheck --leak-check=full -v 

all: $(OBJS)
	$(GCC) $(OBJS) -o pa11

pa11.o: pa11.c linkedlist.h linkedlist.c  calc.c calc.h getString.h getString.c
	$(GCC) -c pa11.c

linkedlist.o:  linkedlist.c linkedlist.h 
	$(GCC)  -c linkedlist.c

calc.o:  calc.c calc.h linkedlist.h linkedlist.c 
	$(GCC) -c calc.c
getString.o: getString.c getString.h
	$(GCC) -c getString.c

test: all
	echo "testing"
	./pa11 inputs/test1 
	./pa11 inputs/test2 
	./pa11 inputs/test3 
	./pa11 inputs/test4 
	./pa11 inputs/test5 

memory: pa11
	$(GRIND) ./pa11 inputs/test1 
	$(GRIND) ./pa11 inputs/test2 
	$(GRIND) ./pa11 inputs/test3
	$(GRIND) ./pa11 inputs/test4 
	$(GRIND) ./pa11 inputs/test5
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov 
	/bin/rm -f pa11
