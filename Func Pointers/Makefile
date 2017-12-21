CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) # $(COVFLAGS) $(PROFFLAG)
OBJS =  pa04.o answer04.o
FUNCS = func1.o func2.o func3.o func4.o func5.o

all: pa04_exe

pa04_exe: pa04


#build each of the executables for integration
pa04: pa04.o answer04.o func1.o func2.o func3.o func4.o func5.o
	$(GCC) pa04.o answer04.o func1.o func2.o func3.o func4.o func5.o -o pa04 -lm


#build pa04 WITH INTEGRATE	
answer04.o: answer04.c pa04.h
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE answer04.c -c


#create .o for all
.c.o: 
	$(GCC) $(CFLAGS) -c $*.c
	
#testing
testall: pa04_exe
	echo "testing integration"
	echo "testing funcs"
	./pa04 testdir/test1 testdir/output_test1 
	./pa04 testdir/test2 testdir/output_test2
	./pa04 testdir/test3 testdir/output_test3
	./pa04 testdir/test4 testdir/output_test4
	./pa04 testdir/test5 testdir/output_test5




clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa04 pa04.prof
	

