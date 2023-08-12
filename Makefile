CC = cc

ROOTPATH=.
INCLUDE = -I$(ROOTPATH)/src
LIB=-lpthread

OBJ += $(patsubst %.c, %.o, $(wildcard *.c))
OBJ += $(patsubst %.c, %.o, $(wildcard $(ROOTPATH)/src/*.c))

CFLAGS = -O0 -g3 -Wall
target = occupy

all:$(OBJ)
	$(CC) out/*.o -o $(target) $(LIB)
	mv $(target) out
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	mv $@ out
clean:
	rm -rf out/*
