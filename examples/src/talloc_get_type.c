#include <talloc.h>

#define ABORT_ON_TYPE_MISMATCH

void my_abort(const char *reason)
{
    fprintf(stderr, "talloc abort: %s\n", reason);
#ifdef ABORT_ON_TYPE_MISMATCH
    abort();
#endif
}

int main(int argc, char **argv)
{
    TALLOC_CTX *ctx = NULL;
    char *str = NULL;

    talloc_set_abort_fn(my_abort);

    ctx = talloc_new(NULL);
    str = talloc_get_type_abort(ctx, char);
    if (str == NULL) {
        return 1;
    }

    return 0;
}
