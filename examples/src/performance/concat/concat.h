#ifndef CONCAT_H_
#define CONCAT_H_

#include <talloc.h>
#include <string.h>

#define COUNT 100000
#define STRING "somestring"
#define POOL_SIZE (sizeof(char) * (500000 + 1)) /* half of the defaults */

int init_args(int argc, char **argv, int *_count, char **_str, size_t *_pool);

char** test_malloc_fill(const char *str, int count);
void test_malloc_free_groups(char **groups, int count);

char** test_talloc_fill(TALLOC_CTX *mem_ctx, const char *str, int count);

#endif /* CONCAT_H_ */
