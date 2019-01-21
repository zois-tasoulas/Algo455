CC 	:= gcc
FLAGS 	:= -Wall -O0 -g
.PHONY: all clean cleanobj

all: p1 p2 cleanobj

p1 : p1.c
	$(CC) $(FLAGS) $^ -o $@

p2 : p2.c
	$(CC) $(FLAGS) $^ -o $@

clean : cleanobj
	rm -f p1 p2

cleanobj : 
	rm -f *.o *~ 
