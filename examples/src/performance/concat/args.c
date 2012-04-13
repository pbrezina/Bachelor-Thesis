#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

int init_args(int argc, char **argv, int *_count, char **_str, size_t *_pool)
{
    int count = COUNT;
    char *str = STRING;
    size_t pool_size = POOL_SIZE;

    if (argc > 1) {
        count = atoi(argv[1]);
    }

    if (argc > 2) {
        pool_size = atoi(argv[2]);
    }

    if (argc > 3) {
        str = argv[3];
    }

    if (argc > 4) {
        fprintf(stderr, "Usage: %s [num_elements [pool_size [string]]]\n",
                argv[0]);
        goto fail;
    }

    printf("Array length : %lu\n", (unsigned long)count);
    printf("Array element: \"%s\"\n", str);
    printf("Pool size    : %lu\n\n", (unsigned long)pool_size);

    *_count = count;
    *_str = str;
    *_pool = pool_size;

    return EOK;

fail:
	return 1;
}
