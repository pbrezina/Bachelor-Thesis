#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "realloc.h"

static void test_talloc_realloc(int loops, size_t size)
{
    TALLOC_CTX *ptr = NULL;
    size_t total = 0;
    int i;

    for (i = 0; i < loops; i++) {
    	total += size;
        ptr = talloc_realloc_size(NULL, ptr, total);
        ENOMEMCHECK(ptr, done);
    }

done:
	talloc_free(ptr);
    return;
}

int main(int argc, char **argv)
{
    int loops = LOOPS;
    size_t size = SIZE;
    int ret;

    ret = init_args(argc, argv, &loops, &size);
    ERRORCHECK(ret != EOK, "Invalid arguments!\n", fail);

	printf("Testing talloc_realloc_size...\n");
	test_talloc_realloc(loops, size);

    return 0;

fail:
    return -1;
}
