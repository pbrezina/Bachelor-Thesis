#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "malloc.h"

static void test_talloc_size_tmp_ctx(int loops, size_t size)
{
    TALLOC_CTX *tmp_ctx = NULL;
    TALLOC_CTX *sub_ctx = NULL;
    int i;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    for (i = 0; i < loops; i++) {
        sub_ctx = talloc_size(tmp_ctx, size);
        ENOMEMCHECK(sub_ctx, done);
    }

done:
    talloc_free(tmp_ctx);
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

    printf("Testing talloc_size with tmp_ctx hierarchy...\n");
    test_talloc_size_tmp_ctx(loops, size);

    return 0;

fail:
    return -1;
}
