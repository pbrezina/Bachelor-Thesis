#ifndef MALLOC_H_
#define MALLOC_H_

#include <string.h>

#define LOOPS     1000
#define SIZE      100
#define POOL_SIZE 10000

void test_malloc_size(int loops, size_t size);

void test_talloc_size(int loops, size_t size);
void test_talloc_size_tmp_ctx(int loops, size_t size);
void test_talloc_pool_exact(int loops, size_t size);
void test_talloc_pool_guess(int loops, size_t size, size_t pool_size);

#endif /* MALLOC_H_ */
