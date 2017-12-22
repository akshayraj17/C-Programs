GCC=gcc -std=c99 -Wall -Werror -Wshadow --pedantic

all: compile

compile: gen.c gen.h
	$(GCC) gen.c -o gen

clean:
	rm -f gen
	rm -f path_*
	rm -f maze

gen: compile
	./gen
