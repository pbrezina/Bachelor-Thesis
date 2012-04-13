#include <stdlib.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

void test_malloc_free_groups(char **groups, int count)
{
    int i;

    if (groups != NULL) {
        for (i = 0; i < count; i++) {
            free(groups[i]);
        }

        free(groups);
    }
}

char** test_malloc_fill(const char *str, int count)
{
    char **groups = NULL;
    int i;

    groups = (char**)calloc(count, sizeof(char*));
    if (groups == NULL) {
        goto fail;
    }

    for (i = 0; i < count; i++) {
        groups[i] = strdup(str);
        if (groups[i] == NULL) {
            goto fail;
        }
    }

    return groups;

fail:
    test_malloc_free_groups(groups, count);
    return NULL;
}
