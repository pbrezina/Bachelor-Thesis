#include <stdlib.h>

#include "../../common.h"
#include "calloc.h"

static void test_calloc(int loops, size_t count)
{
    void *ptr = NULL;
    int i;

    for (i = 0; i < loops; i++) {
        ptr = calloc(count, sizeof(int));
        ENOMEMCHECK(ptr, done);

        free(ptr);
    }

done:
    return;
}

int main(int argc, char **argv)
{
    int loops = LOOPS;
    size_t count = COUNT;
    int ret;

    ret = init_args(argc, argv, &loops, &count);
    ERRORCHECK(ret != EOK, "Invalid arguments!\n", fail);

	printf("Testing calloc...\n");
	test_calloc(loops, count);

    return 0;

fail:
    return -1;
}
