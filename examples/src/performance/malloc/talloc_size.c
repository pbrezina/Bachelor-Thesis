#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "malloc.h"

static void test_talloc_size(int loops, size_t size)
{
    TALLOC_CTX *ptr = NULL;
    int i;

    for (i = 0; i < loops; i++) {
        ptr = talloc_size(NULL, size);
        ENOMEMCHECK(ptr, done);

        talloc_free(ptr);
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

    printf("Testing talloc_size...\n");
    test_talloc_size(loops, size);

    return 0;

fail:
    return -1;
}
