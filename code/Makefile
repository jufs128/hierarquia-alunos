ALL = tp1
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

CC = gcc

CFLAGS = -lm

all: $(ALL)

$(ALL): $(OBJ) 
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $@ 

clean:
	rm $(ALL) *.o
