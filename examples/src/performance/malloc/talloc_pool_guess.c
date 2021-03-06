#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "malloc.h"

static void test_talloc_pool_guess(int loops, size_t size, size_t pool_size)
{
    TALLOC_CTX *pool_ctx = NULL;
    TALLOC_CTX *sub_ctx = NULL;
    int i;

    pool_ctx = talloc_pool(NULL, pool_size);
    ENOMEMCHECK(pool_ctx, done);

    for (i = 0; i < loops; i++) {
        sub_ctx = talloc_size(pool_ctx, size);
        ENOMEMCHECK(sub_ctx, done);
    }

done:
    talloc_free(pool_ctx);
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

    printf("Testing talloc_pool with selected size...\n");
    test_talloc_pool_guess(loops, size, pool_size);

    return 0;

fail:
    return -1;
}
