# You need to write this file so that
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
//PROFFLAG = -pg
GCC = gcc $(CFLAGS) # $(COVFLAGS) $(PROFFLAG)
OBJS = pa06.o student.o
GRIND = valgrind --tool=memcheck --leak-check=full

# "make" will create an executable called pa05
all: pa06

# "make test" will run the three input files 
pa06: pa06.o student.o msort.o 
	$(GCC) pa06.o student.o msort.o -o pa06

msort.o: msort.c
	$(GCC) msort.c -c

# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3
test: pa06
	echo "testing"
	./pa06 inputs/testinput1 id1 first1 last1
	./pa06 inputs/testinput2 id2 first2 last2
	./pa06 inputs/testinput3 id3 first3 last3
# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
#
# "make memory" calls valgrind to check memory errors
memory: pa06
	$(GRIND) ./pa06 inputs/testinput1 id1 first1 last1
	$(GRIND) ./pa06 inputs/testinput2 id2 first2 last2
	$(GRIND) ./pa06 inputs/testinput3 id3 first3 last3


# "make clean" remove .o and all output files
clean: 
	
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa06.prof
	/bin/rm -f pa06
	/bin/rm first* last* id*
