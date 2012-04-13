#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

static char* test_talloc_append_pool_guess(TALLOC_CTX *mem_ctx,
                                           char **groups, int count,
                                           size_t pool_size)
{
    TALLOC_CTX *pool_ctx = NULL;
    size_t len_total = 0;
    char *str = NULL;
    char *out = NULL;
    int i;

    for (i = 0; i < count; i++) {
        len_total += strlen(groups[i]);
    }

    pool_ctx = talloc_pool(NULL, pool_size);
    if (pool_ctx == NULL) {
        goto done;
    }

    str = talloc_zero(pool_ctx, char); /* assign to pool_ctx */
    if (str == NULL) {
        goto done;
    }

    for (i = 0; i < count; i++) {
        str = talloc_strdup_append(str, groups[i]);
        if (str == NULL) {
            goto done;
        }
    }

    out = talloc_memdup(mem_ctx, str, talloc_get_size(str));

done:
    talloc_free(pool_ctx);
    return out;
}

int main(int argc, char **argv)
{
    TALLOC_CTX *tmp_ctx = NULL;
    int count = COUNT;
    char *str = STRING;
    size_t pool_size = POOL_SIZE;
    char *filter = NULL;
    char **groups = NULL;
    int ret;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    ret = init_args(argc, argv, &count, &str, &pool_size);
    ERRORCHECK(ret != EOK, "Invalid arguments!\n", fail);

    groups = test_talloc_fill(tmp_ctx, str, count);
    ENOMEMCHECK(groups, done);

    filter = test_talloc_append_pool_guess(tmp_ctx, groups, count, pool_size);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
    return 0;

fail:
    return -1;
}
