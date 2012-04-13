#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "malloc.h"

int init_args(int argc, char **argv, int *_loops, size_t *_size, size_t *_pool)
{
    int loops = LOOPS;
    size_t size = SIZE;
    size_t pool_size = POOL_SIZE;

    if (argc > 1) {
        loops = atoi(argv[1]);
    }

    if (argc > 2) {
        size = atoi(argv[2]);
    }

    if (argc > 3) {
        pool_size = atoi(argv[3]);
    }

    if (argc > 4) {
        fprintf(stderr, "Usage: %s "
                "[num_loops [malloc_size [pool_size]]]\n", argv[0]);
        goto fail;
    }

    printf("Loops count : %d\n", loops);
    printf("Block size  : %lu\n", (unsigned long)size);
    printf("Pool size   : %lu\n", (unsigned long)pool_size);

    *_loops = loops;
    *_size = size;
    *_pool = pool_size;

    return EOK;

fail:
	return 1;
}
