CFLAGS = -std=c99 -g -Wall -Werror -Wshadow --pedantic -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFLAG = -pg
GCC = gcc $(CFLAGS)  $(COVFLAGS) #$(PROFFLAG)
OBJS = bmp.o filter.o pa13.o 
GRIND = valgrind --tool=memcheck --leak-check=full -v 

all: $(OBJS)
	$(GCC) $(OBJS) -o pa13

pa13.o: pa13.c bmp.c filter.c bmp.h filter.h 
	$(GCC) -c pa13.c

filter.o: pa13.c bmp.c filter.c bmp.h filter.h 
	$(GCC) -c filter.c

bmp.o: pa13.c bmp.c filter.c bmp.h filter.h 
	$(GCC) -c bmp.c


test: all
	echo "testing"
	./pa13 test.bmp out.bmp sharpen.filter


memory: pa13
	$(GRIND) ./pa13 test.bmp out.bmp sharpen.filter

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa13
	/bin/rm -f out.bmp
