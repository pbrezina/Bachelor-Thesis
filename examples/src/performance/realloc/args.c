#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "realloc.h"

int init_args(int argc, char **argv, int *_loops, size_t *_size)
{
    int loops = LOOPS;
    size_t size = SIZE;

    if (argc > 1) {
        loops = atoi(argv[1]);
    }

    if (argc > 2) {
        size = atoi(argv[2]);
    }

    if (argc > 3) {
        fprintf(stderr, "Usage: %s "
        		"[num_loops [realloc_size]]\n", argv[0]);
        goto fail;
    }

    printf("Loops count : %d\n", loops);
    printf("Block size  : %lu\n", (unsigned long)size);

    *_loops = loops;
    *_size = size;

    return EOK;

fail:
	return 1;
}
