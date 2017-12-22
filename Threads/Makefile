CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code -Wvla 
COVFLAGS = -fprofile-arcs -ftest-coverage
LFLAGS = -lpthread
PROFLAGS = -pg 
GCC = gcc $(CFLAGS) $(LFLAGS) #$(PROFFLAG)
OBJS = bmp.o filterParallel.o pa14.o 
GRIND = valgrind --tool=memcheck --leak-check=full -v 

all: $(OBJS)
	$(GCC) $(OBJS) -o pa14

pa14.o: pa14.c bmp.c filterParallel.c bmp.h filterParallel.h 
	$(GCC) -c pa14.c

filterParallel.o: pa14.c bmp.c filterParallel.c bmp.h filterParallel.h 
	$(GCC) -c filterParallel.c

bmp.o: pa14.c bmp.c filterParallel.c bmp.h filterParallel.h 
	$(GCC) -c bmp.c


test: all
	echo "testing"
	./pa14 test.bmp output.bmp 

memory: pa14
	$(GRIND) ./pa14 test.bmp output.bmp 
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa14
	/bin/rm -f output.bmp
