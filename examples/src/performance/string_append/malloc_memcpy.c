#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "string_append.h"

static char* test_malloc_filter_memcpy(char **groups, int count)
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

static char* test_malloc_filter_memcpy_malloc(char **groups, int count)
{
    size_t len_total = 0;
    size_t len_cur = 0;
    char *str = NULL;
    int i;

    for (i = 0; i < count; i++) {
        len_total += strlen(groups[i]);
    }

    str = (char*)malloc(sizeof(char) * (len_total + 1));
    if (str == NULL) {
        goto fail;
    }

    len_total = 0;
    for (i = 0; i < count; i++) {
        len_cur = strlen(groups[i]);
        len_total += len_cur;

        memcpy(&str[len_total - len_cur], groups[i], len_cur);
        str[len_total] = '\0';
    }

    return str;

fail:
    free(str);
    return NULL;
}

void test_malloc_memcpy(int count, const char *str)
{
    char *filter = NULL;
    char **groups = NULL;

    groups = test_malloc_fill(str, count);
    ENOMEMCHECK(groups, done);

    filter = test_malloc_filter_memcpy(groups, count);
    ENOMEMCHECK(filter, done);

done:
    test_malloc_free_groups(groups, count);
    free(filter);
}

void test_malloc_memcpy_malloc(int count, const char *str)
{
    char *filter = NULL;
    char **groups = NULL;

    groups = test_malloc_fill(str, count);
    ENOMEMCHECK(groups, done);

    filter = test_malloc_filter_memcpy_malloc(groups, count);
    ENOMEMCHECK(filter, done);

done:
    test_malloc_free_groups(groups, count);
    free(filter);
}
