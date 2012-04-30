#include <talloc.h>

int main(int argc, char **argv)
{
    /* allocate 1KiB in a pool */
    TALLOC_CTX *pool_ctx = talloc_pool(NULL, 1024);

    /* take 512B from the pool, 512B is left there */
    void *ptr = talloc_size(pool_ctx, 512);

    /* 1024B > 512B, this will create new talloc chunk outside
     * the pool */

    void *ptr2 = talloc_size(ptr, 1024);

    /* the pool still contains 512 free bytes
     * this will take 200B from them */
    void *ptr3 = talloc_size(ptr, 200);

    /* this will destroy context ’ptr3’ but the memory
     * is not freed, the available space in the pool
     * will increase to 512B */
    talloc_free(ptr3);

    /* this will free memory taken by ’pool_ctx’
     * and ’ptr2’ as well */
    talloc_free(pool_ctx);

    return 0;
}
