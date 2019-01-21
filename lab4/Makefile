CC 	:= gcc
FLAGS 	:= -Wall -O0 -g
.PHONY: all clean cleanobj

all: p1 cleanobj

p1 : p1.c
	$(CC) $(FLAGS) $^ -o $@

clean : cleanobj
	rm -f p1

cleanobj :
	rm -f *.o *~ 
