#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "string_append.h"

static char* test_talloc_filter_buffer(TALLOC_CTX *mem_ctx, char **groups, int count)
{
    char *str = NULL;
    int i;

    for (i = 0; i < count; i++) {
        str = talloc_strdup_append_buffer(str, groups[i]);
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

static char* test_talloc_filter_buffer_exact_pool(TALLOC_CTX *mem_ctx, char **groups, int count)
{
    TALLOC_CTX *pool_ctx = NULL;
    size_t len_total = 0;
    char *str = NULL;
    char *out = NULL;
    int i;

    for (i = 0; i < count; i++) {
        len_total += strlen(groups[i]);
    }

    pool_ctx = talloc_pool(NULL, sizeof(char) * (len_total + 1));
    if (pool_ctx == NULL) {
        goto done;
    }

    str = talloc_zero(pool_ctx, char); /* assign to pool_ctx */
    if (str == NULL) {
        goto done;
    }

    for (i = 0; i < count; i++) {
        str = talloc_strdup_append_buffer(str, groups[i]);
        if (str == NULL) {
            goto done;
        }
    }

    out = talloc_memdup(mem_ctx, str, talloc_get_size(str));

done:
    talloc_free(pool_ctx);
    return out;
}

static char* test_talloc_filter_buffer_guess_pool(TALLOC_CTX *mem_ctx, char **groups, int count)
{
    TALLOC_CTX *pool_ctx = NULL;
    size_t len_total = 0;
    char *str = NULL;
    char *out = NULL;
    int i;

    for (i = 0; i < count; i++) {
        len_total += strlen(groups[i]);
    }

    pool_ctx = talloc_pool(NULL, POOL_GUESS);
    if (pool_ctx == NULL) {
        goto done;
    }

    str = talloc_zero(pool_ctx, char); /* assign to pool_ctx */
    if (str == NULL) {
        goto done;
    }

    for (i = 0; i < count; i++) {
        str = talloc_strdup_append_buffer(str, groups[i]);
        if (str == NULL) {
            goto done;
        }
    }

    out = talloc_memdup(mem_ctx, str, talloc_get_size(str));

done:
    talloc_free(pool_ctx);
    return out;
}

static char* test_talloc_filter_buffer_parent_pool(TALLOC_CTX *mem_ctx, char **groups, int count)
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

void test_talloc_append_buffer(int count, const char *str)
{
    TALLOC_CTX *tmp_ctx = NULL;
    char *filter = NULL;
    char **groups = NULL;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    groups = test_talloc_fill(tmp_ctx, str, count);
    ENOMEMCHECK(groups, done);

    filter = test_talloc_filter_buffer(tmp_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
}

void test_talloc_append_buffer_exact_pool(int count, const char *str)
{
    TALLOC_CTX *tmp_ctx = NULL;
    char *filter = NULL;
    char **groups = NULL;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    groups = test_talloc_fill(tmp_ctx, str, count);
    ENOMEMCHECK(groups, done);

    filter = test_talloc_filter_buffer_exact_pool(tmp_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
}

void test_talloc_append_buffer_guess_pool(int count, const char *str)
{
    TALLOC_CTX *tmp_ctx = NULL;
    char *filter = NULL;
    char **groups = NULL;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    groups = test_talloc_fill(tmp_ctx, str, count);
    ENOMEMCHECK(groups, done);

    filter = test_talloc_filter_buffer_guess_pool(tmp_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
}

void test_talloc_append_buffer_parent_exact_pool(int count, const char *str)
{
    TALLOC_CTX *tmp_ctx = NULL;
    TALLOC_CTX *pool_ctx = NULL;
    char *filter = NULL;
    char **groups = NULL;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    groups = test_talloc_fill(tmp_ctx, str, count);
    ENOMEMCHECK(groups, done);

    pool_ctx = talloc_pool(tmp_ctx, sizeof(char) * (strlen(str) * count + 1));
    ENOMEMCHECK(pool_ctx, done);

    filter = test_talloc_filter_buffer_parent_pool(pool_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
}

void test_talloc_append_buffer_parent_guess_pool(int count, const char *str)
{
    TALLOC_CTX *tmp_ctx = NULL;
    TALLOC_CTX *pool_ctx = NULL;
    char *filter = NULL;
    char **groups = NULL;

    tmp_ctx = talloc_new(NULL);
    ENOMEMCHECK(tmp_ctx, done);

    groups = test_talloc_fill(tmp_ctx, str, count);
    ENOMEMCHECK(groups, done);

    pool_ctx = talloc_pool(tmp_ctx, POOL_GUESS);
    ENOMEMCHECK(pool_ctx, done);

    filter = test_talloc_filter_buffer_parent_pool(pool_ctx, groups, count);
    ENOMEMCHECK(filter, done);

done:
    talloc_free(tmp_ctx);
}
