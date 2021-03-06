#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

static char* test_talloc_buffer_parent_pool_guess(TALLOC_CTX *mem_ctx,
                                                  char **groups,
                                                  int count)
{
    char *str = NULL;
    int i;

    str = talloc_zero(mem_ctx, char); /* assign to pool_ctx */
    if (str == NULL) {
        goto fail;
    }

    for (i = 0; i < count; i++) {
        str = talloc_strdup_append_buffer(str, groups[i]);
        if (str == NULL) {
            goto fail;
        }
    }

    return str;

fail:
    talloc_free(str);
    return NULL;
}

int main(int argc, char **argv)
{
    TALLOC_CTX *tmp_ctx = NULL;
    TALLOC_CTX *pool_ctx = NULL;
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

    pool_ctx = talloc_pool(tmp_ctx, pool_size);
    ENOMEMCHECK(pool_ctx, done);

    filter = test_talloc_buffer_parent_pool_guess(pool_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
    return 0;

fail:
    return -1;
}
