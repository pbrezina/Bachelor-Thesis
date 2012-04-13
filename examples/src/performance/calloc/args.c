#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "calloc.h"

int init_args(int argc, char **argv, int *_loops, size_t *_count)
{
    int loops = LOOPS;
    int count = COUNT;

    if (argc > 1) {
        loops = atoi(argv[1]);
    }

    if (argc > 2) {
        count = atoi(argv[2]);
    }

    if (argc > 3) {
        fprintf(stderr, "Usage: %s "
        		"[num_loops [count]]\n", argv[0]);
        goto fail;
    }

    printf("Loops count : %d\n", loops);
    printf("Array length: %lu\n\n", (unsigned long)count);

    *_loops = loops;
    *_count = count;

    return EOK;

fail:
	return 1;
}
