#include <talloc.h>
#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "malloc.h"

int main(int argc, char **argv)
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
        fprintf(stderr, "Usage: %s [num_loops [malloc_size [pool_size]]]", argv[0]);
        goto fail;
    }

    printf("Loops count: %d\n", loops);
    printf("Block size : %lu\n", (unsigned long)size);
    printf("Pool size  : %lu\n\n", (unsigned long)pool_size);

    printf("Testing malloc...\n");
    test_malloc_size(loops, size);

    printf("Testing talloc size...\n");
    test_talloc_size(loops, size);

    printf("Testing talloc size with tmp_ctx...\n");
    test_talloc_size_tmp_ctx(loops, size);

    printf("Testing talloc pool with exact size...\n");
	test_talloc_pool_exact(loops, size);

	printf("Testing talloc pool of size %lu...\n", (unsigned long)pool_size);
	test_talloc_pool_guess(loops, size, pool_size);

    return 0;

fail:
    return -1;
}
