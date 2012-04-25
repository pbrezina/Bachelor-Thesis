#include <stdlib.h>

#include "../../common.h"
#include "malloc.h"

void test_malloc_size(int loops, size_t size)
{
    void *ptr = NULL;
    int i;

    for (i = 0; i < loops; i++) {
        ptr = malloc(size);
        ENOMEMCHECK(ptr, done);

        free(ptr);
    }

done:
    return;
}

