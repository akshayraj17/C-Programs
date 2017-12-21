# You need to write this file so that
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
//PROFFLAG = -pg
GCC = gcc $(CFLAGS) # $(COVFLAGS) $(PROFFLAG)
OBJS = pa05.o student.o
GRIND = valgrind --tool=memcheck --leak-check=full

# "make" will create an executable called pa05
all: pa05

# "make test" will run the three input files 
pa05: pa05.o student.o 
	$(GCC) pa05.o student.o -o pa05
student.o: student.c constant.h student.h
	$(GCC) -DTEST_READ -DTEST_WRITE -DTEST_ID -DTEST_FIRSTNAME -DTEST_LASTNAME -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME student.c -c

pa05.o: pa05.c
	$(GCC) pa05.c -c

# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3
test: pa05
	echo "testing"
	./pa05 inputs/testinput1 id1 first1 last1
	./pa05 inputs/testinput2 id2 first2 last2
	./pa05 inputs/testinput3 id3 first3 last3
# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
#
# "make memory" calls valgrind to check memory errors
memory: pa05
	$(GRIND) ./pa05 inputs/testinput1 id1 first1 last1
	$(GRIND) ./pa05 inputs/testinput2 id2 first2 last2
	$(GRIND) ./pa05 inputs/testinput3 id3 first3 last3


# "make clean" remove .o and all output files
clean: 
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa05.prof
	/bin/rm -f pa05
