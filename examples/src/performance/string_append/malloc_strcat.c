#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "string_append.h"

static char* test_malloc_filter_strcat(char **groups, int count)
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

        /* strncat(str, groups[i], len_cur); */
        strcat(str, groups[i]);
    }

    return str;

fail:
    free(str);
    return NULL;
}

static char* test_malloc_filter_strcat_malloc(char **groups, int count)
{
    size_t len_total = 0;
    char *str = NULL;
    int i;

    for (i = 0; i < count; i++) {
        len_total += strlen(groups[i]);
    }

    str = (char*)malloc(sizeof(char) * (len_total + 1));
    if (str == NULL) {
        goto fail;
    }

    for (i = 0; i < count; i++) {
        strcat(str, groups[i]);
    }

    return str;

fail:
    free(str);
    return NULL;
}

void test_malloc_strcat(int count, const char *str)
{
    char *filter = NULL;
    char **groups = NULL;

    groups = test_malloc_fill(str, count);
    ENOMEMCHECK(groups, done);

    filter = test_malloc_filter_strcat(groups, count);
    ENOMEMCHECK(filter, done);

done:
    test_malloc_free_groups(groups, count);
    free(filter);
}

void test_malloc_strcat_malloc(int count, const char *str)
{
    char *filter = NULL;
    char **groups = NULL;

    groups = test_malloc_fill(str, count);
    ENOMEMCHECK(groups, done);

    filter = test_malloc_filter_strcat_malloc(groups, count);
    ENOMEMCHECK(filter, done);

done:
    test_malloc_free_groups(groups, count);
    free(filter);
}
