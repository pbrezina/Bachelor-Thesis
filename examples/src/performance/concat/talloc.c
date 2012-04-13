#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "concat.h"

char** test_talloc_fill(TALLOC_CTX *mem_ctx, const char *str, int count)
{
    TALLOC_CTX *tmp_ctx = NULL;
    char **groups = NULL;
    int i;

    tmp_ctx = talloc_new(NULL);
    if (tmp_ctx == NULL) {
        goto fail;
    }

    groups = talloc_array(tmp_ctx, char*, count);
    if (groups == NULL) {
        goto fail;
    }

    for (i = 0; i < count; i++) {
        groups[i] = talloc_strdup(groups, str);
        if (groups[i] == NULL) {
            goto fail;
        }
    }

    talloc_steal(mem_ctx, groups);
    goto done;

fail:
    groups = NULL;

done:
    talloc_free(tmp_ctx);
    return groups;
}
