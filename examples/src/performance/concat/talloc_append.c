#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

static char* test_talloc_append(TALLOC_CTX *mem_ctx, char **groups, int count)
{
    char *str = NULL;
    int i;

    for (i = 0; i < count; i++) {
        str = talloc_strdup_append(str, groups[i]);
        if (str == NULL) {
            goto fail;
        }
    }

    talloc_steal(mem_ctx, str);
    return str;

fail:
    talloc_free(str);
    return NULL;
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

    filter = test_talloc_append(tmp_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
    return 0;

fail:
    return -1;
}
