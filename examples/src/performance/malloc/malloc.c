#include <stdlib.h>

#include "../../common.h"
#include "malloc.h"

static void test_malloc(int loops, size_t size)
{
    void *ptr = NULL;
    int i;

    for (i = 0; i < loops; i++) {
        ptr = malloc(size);
        ENOMEMCHECK(ptr, done);

        free(ptr);
    }

done:
    return;
}

int main(int argc, char **argv)
{
    int loops = LOOPS;
    size_t size = SIZE;
    size_t pool_size = POOL_SIZE;

    int ret;

    ret = init_args(argc, argv, &loops, &size, &pool_size);
    ERRORCHECK(ret != EOK, "Invalid arguments!\n", fail);

    printf("Testing malloc...\n");
    test_malloc(loops, size);

    return 0;

fail:
    return -1;
}
