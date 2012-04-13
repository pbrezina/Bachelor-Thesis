#include <talloc.h>
#include <string.h>

#include "../../common.h"
#include "calloc.h"

static void test_talloc_zero_array(int loops, size_t count)
{
    TALLOC_CTX *ptr = NULL;
    int i;

    for (i = 0; i < loops; i++) {
        ptr = talloc_zero_array(NULL, int, count);
        ENOMEMCHECK(ptr, done);

        talloc_free(ptr);
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

	printf("Testing talloc_zero_array...\n");
	test_talloc_zero_array(loops, count);

    return 0;

fail:
    return -1;
}
