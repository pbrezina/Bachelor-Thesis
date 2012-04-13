CC=gcc
CFLAGS=-O0 -ggdb3 -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Werror
LIBS=-ltalloc
CMPL=$(CC) $(CFLAGS) $(LIBS)
SRC=src
PERFORMANCE=$(SRC)/performance
BIN=bin

clean:
	rm -fr $(BIN)

performance-test-1:
	$(CMPL) -o $(BIN)/performance-test-1 $(PERFORMANCE)/test1.c
