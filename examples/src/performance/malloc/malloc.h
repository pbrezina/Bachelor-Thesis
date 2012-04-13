#ifndef MALLOC_H_
#define MALLOC_H_

#include <string.h>

#define LOOPS     1000
#define SIZE      100
#define POOL_SIZE 10000

int init_args(int argc, char **argv, int *_loops, size_t *_size, size_t *_pool);

#endif /* MALLOC_H_ */
