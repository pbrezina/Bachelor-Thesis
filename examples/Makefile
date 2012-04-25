CC=gcc
CFLAGS=-O0 -ggdb3 -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Werror
LIBS=-ltalloc
CMPL=$(CC) $(CFLAGS) $(LIBS)
SRC=src
PERFORMANCE=$(SRC)/performance
BIN=bin

clean:
	rm -fr $(BIN)
	
init:
	mkdir -p $(BIN)

perftest-string-append: init
	$(CMPL) -o $(BIN)/perftest-string-append  \
		$(PERFORMANCE)/string_append/main.c   \
		$(PERFORMANCE)/string_append/malloc.c \
		$(PERFORMANCE)/string_append/malloc_strcat.c \
		$(PERFORMANCE)/string_append/malloc_strncat.c \
		$(PERFORMANCE)/string_append/malloc_memcpy.c \
		$(PERFORMANCE)/string_append/talloc.c \
		$(PERFORMANCE)/string_append/talloc_append.c \
		$(PERFORMANCE)/string_append/talloc_append_buffer.c

perftest-malloc: init
	$(CMPL) -o $(BIN)/perftest-malloc  \
		$(PERFORMANCE)/malloc/main.c   \
		$(PERFORMANCE)/malloc/malloc.c \
		$(PERFORMANCE)/malloc/talloc.c
