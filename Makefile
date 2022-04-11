# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# pickp all sources
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)

# define targets
TARGETS=ninel codeinvim vectsecv nomogram

build: $(OBJS) $(TARGETS)

ninel: ninel.c
	$(CC) $(CFLAGS) $@.o -o $@

codeinvim: codeinvim.c
	$(CC) $(CFLAGS) $@.o -o $@

vectsecv: vectsecv.c
	$(CC) $(CFLAGS) $@.o -o $@

nomogram: nomogram.c
	$(CC) $(CFLAGS) $@.o -o $@


clean:
	rm -f $(TARGETS) $(OBJS)

.PHONY: pack clean