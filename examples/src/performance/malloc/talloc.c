#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "malloc.h"

void test_talloc_size(int loops, size_t size)
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

void test_talloc_size_tmp_ctx(int loops, size_t size)
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

void test_talloc_pool_exact(int loops, size_t size)
{
    TALLOC_CTX *pool_ctx = NULL;
    TALLOC_CTX *sub_ctx = NULL;
    int i;

    pool_ctx = talloc_pool(NULL, size * loops);
    ENOMEMCHECK(pool_ctx, done);

    for (i = 0; i < loops; i++) {
        sub_ctx = talloc_size(pool_ctx, size);
        ENOMEMCHECK(sub_ctx, done);
    }

done:
    talloc_free(pool_ctx);
    return;
}

void test_talloc_pool_guess(int loops, size_t size, size_t pool_size)
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

