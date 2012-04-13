#include <stdlib.h>

#include "../../common.h"
#include "realloc.h"

static void test_realloc(int loops, size_t size)
{
    void *ptr = NULL;
    size_t total = 0;
    int i;

    for (i = 0; i < loops; i++) {
    	total += size;
        ptr = realloc(ptr, total);
        ENOMEMCHECK(ptr, done);
    }

done:
	free(ptr);
    return;
}

int main(int argc, char **argv)
{
    int loops = LOOPS;
    size_t size = SIZE;
    int ret;

    ret = init_args(argc, argv, &loops, &size);
    ERRORCHECK(ret != EOK, "Invalid arguments!\n", fail);

	printf("Testing realloc...\n");
	test_realloc(loops, size);

    return 0;

fail:
    return -1;
}
