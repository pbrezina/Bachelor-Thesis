#ifndef STRING_APPEND_H_
#define STRING_APPEND_H_

#include <talloc.h>

#define COUNT 100000
#define POOL_GUESS (sizeof(char) * (500000 + 1)) /* half of the defaults */

/* DATA */

char** test_talloc_fill(TALLOC_CTX *mem_ctx, const char *str, int count);

char** test_malloc_fill(const char *str, int count);
void test_malloc_free_groups(char **groups, int count);

/* MAIN TESTS */

void test_malloc_strcat(int count, const char *str);
void test_malloc_strcat_malloc(int count, const char *str);

void test_malloc_strncat(int count, const char *str);
void test_malloc_strncat_malloc(int count, const char *str);

void test_malloc_memcpy(int count, const char *str);
void test_malloc_memcpy_malloc(int count, const char *str);

void test_talloc_append(int count, const char *str);
void test_talloc_append_exact_pool(int count, const char *str);
void test_talloc_append_guess_pool(int count, const char *str);
void test_talloc_append_parent_exact_pool(int count, const char *str);
void test_talloc_append_parent_guess_pool(int count, const char *str);

void test_talloc_append_buffer(int count, const char *str);
void test_talloc_append_buffer_exact_pool(int count, const char *str);
void test_talloc_append_buffer_guess_pool(int count, const char *str);
void test_talloc_append_buffer_parent_exact_pool(int count, const char *str);
void test_talloc_append_buffer_parent_guess_pool(int count, const char *str);

#endif /* STRING_APPEND_H_ */
