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

perftest-concat-strcat: init
	$(CMPL) -o $(BIN)/perftest-concat-strcat  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/malloc.c   \
		$(PERFORMANCE)/concat/malloc_strcat.c

perftest-concat-strcat-pool: init
	$(CMPL) -o $(BIN)/perftest-concat-strcat-pool  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/malloc.c   \
		$(PERFORMANCE)/concat/malloc_strcat_pool.c

perftest-concat-strncat: init
	$(CMPL) -o $(BIN)/perftest-concat-strncat  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/malloc.c   \
		$(PERFORMANCE)/concat/malloc_strncat.c

perftest-concat-strncat-pool: init
	$(CMPL) -o $(BIN)/perftest-concat-strncat-pool  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/malloc.c   \
		$(PERFORMANCE)/concat/malloc_strncat_pool.c

perftest-concat-memcpy: init
	$(CMPL) -o $(BIN)/perftest-concat-memcpy  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/malloc.c   \
		$(PERFORMANCE)/concat/malloc_memcpy.c

perftest-concat-memcpy-pool: init
	$(CMPL) -o $(BIN)/perftest-concat-memcpy-pool  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/malloc.c   \
		$(PERFORMANCE)/concat/malloc_memcpy_pool.c

perftest-concat-append: init
	$(CMPL) -o $(BIN)/perftest-concat-append  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/talloc.c   \
		$(PERFORMANCE)/concat/talloc_append.c

perftest-concat-append-parent-pool-exact: init
	$(CMPL) -o $(BIN)/perftest-concat-append-parent-pool-exact  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/talloc.c   \
		$(PERFORMANCE)/concat/talloc_append_parent_pool_exact.c

perftest-concat-append-parent-pool-guess: init
	$(CMPL) -o $(BIN)/perftest-concat-append-parent-pool-guess  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/talloc.c   \
		$(PERFORMANCE)/concat/talloc_append_parent_pool_guess.c

perftest-concat-buffer: init
	$(CMPL) -o $(BIN)/perftest-concat-buffer  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/talloc.c   \
		$(PERFORMANCE)/concat/talloc_buffer.c

perftest-concat-buffer-parent-pool-exact: init
	$(CMPL) -o $(BIN)/perftest-concat-buffer-parent-pool-exact  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/talloc.c   \
		$(PERFORMANCE)/concat/talloc_buffer_parent_pool_exact.c

perftest-concat-buffer-parent-pool-guess: init
	$(CMPL) -o $(BIN)/perftest-concat-buffer-parent-pool-guess  \
		$(PERFORMANCE)/concat/args.c   \
		$(PERFORMANCE)/concat/talloc.c   \
		$(PERFORMANCE)/concat/talloc_buffer_parent_pool_guess.c

perftest-malloc-std: init
	$(CMPL) -o $(BIN)/perftest-malloc-std  \
		$(PERFORMANCE)/malloc/args.c   \
		$(PERFORMANCE)/malloc/malloc.c

perftest-malloc-talloc-size: init
	$(CMPL) -o $(BIN)/perftest-malloc-talloc-size  \
		$(PERFORMANCE)/malloc/args.c   \
		$(PERFORMANCE)/malloc/talloc_size.c

perftest-malloc-talloc-tmpctx: init
	$(CMPL) -o $(BIN)/perftest-malloc-talloc-tmpctx  \
		$(PERFORMANCE)/malloc/args.c   \
		$(PERFORMANCE)/malloc/talloc_size_tmp.c

perftest-malloc-talloc-pool-exact: init
	$(CMPL) -o $(BIN)/perftest-malloc-talloc-pool-exact  \
		$(PERFORMANCE)/malloc/args.c   \
		$(PERFORMANCE)/malloc/talloc_pool_exact.c

perftest-malloc-talloc-pool-guess: init
	$(CMPL) -o $(BIN)/perftest-malloc-talloc-pool-guess  \
		$(PERFORMANCE)/malloc/args.c   \
		$(PERFORMANCE)/malloc/talloc_pool_guess.c

perftest-calloc-std: init
	$(CMPL) -o $(BIN)/perftest-calloc-std  \
		$(PERFORMANCE)/calloc/args.c \
		$(PERFORMANCE)/calloc/malloc.c

perftest-calloc-talloc: init
	$(CMPL) -o $(BIN)/perftest-calloc-talloc  \
		$(PERFORMANCE)/calloc/args.c \
		$(PERFORMANCE)/calloc/talloc.c

perftest-realloc-std: init
	$(CMPL) -o $(BIN)/perftest-realloc-std  \
		$(PERFORMANCE)/realloc/args.c \
		$(PERFORMANCE)/realloc/malloc.c

perftest-realloc-talloc: init
	$(CMPL) -o $(BIN)/perftest-realloc-talloc  \
		$(PERFORMANCE)/realloc/args.c \
		$(PERFORMANCE)/realloc/talloc.c

double-free: init
	$(CMPL) -o $(BIN)/double-free  \
		$(SRC)/double_free.c

invalid-context: init
	$(CMPL) -o $(BIN)/invalid-context  \
		$(SRC)/invalid_context.c

report: init
	$(CMPL) -o $(BIN)/report  \
		$(SRC)/report.c

struct-user: init
	$(CMPL) -o $(BIN)/struct-user  \
		$(SRC)/struct_user.c

array-length: init
	$(CMPL) -o $(BIN)/array-length  \
		$(SRC)/talloc_array_length.c

get-type: init
	$(CMPL) -o $(BIN)/get-type  \
		$(SRC)/talloc_get_type.c

move: init
	$(CMPL) -o $(BIN)/move  \
		$(SRC)/talloc_move.c

new: init
	$(CMPL) -o $(BIN)/new  \
		$(SRC)/talloc_new.c
		
pool: init
	$(CMPL) -o $(BIN)/pool  \
		$(SRC)/talloc_pool.c

strlen: init
	$(CMPL) -o $(BIN)/strlen  \
		$(SRC)/talloc_strlen.c

zero: init
	$(CMPL) -o $(BIN)/zero  \
		$(SRC)/talloc_zero.c
