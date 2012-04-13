#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

static char* test_malloc_memcpy(char **groups, int count)
{
    size_t len_total = 0;
    size_t len_cur = 0;
    char *str = NULL;
    int i;

    for (i = 0; i < count; i++) {
        len_cur = strlen(groups[i]);
        len_total += len_cur;

        str = (char*)realloc(str, sizeof(char) * (len_total + 1));
        if (str == NULL) {
            goto fail;
        }

        memcpy(&str[len_total - len_cur], groups[i], len_cur);
        str[len_total] = '\0';
    }

    return str;

fail:
    free(str);
    return NULL;
}

int main(int argc, char **argv)
{
    int count = COUNT;
    char *str = STRING;
    size_t pool_size = POOL_SIZE;
    char *filter = NULL;
    char **groups = NULL;
    int ret;

    ret = init_args(argc, argv, &count, &str, &pool_size);
    ERRORCHECK(ret != EOK, "Invalid arguments!\n", fail);

    groups = test_malloc_fill(str, count);
    ENOMEMCHECK(groups, done);

    filter = test_malloc_memcpy(groups, count);
    ENOMEMCHECK(filter, done);

done:
    test_malloc_free_groups(groups, count);
    free(filter);
    return 0;

fail:
    return -1;
}
