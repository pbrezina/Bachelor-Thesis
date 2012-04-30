#include <talloc.h>

int main(int argc, char **argv)
{
    talloc_set_log_stderr();
    TALLOC_CTX *ctx = talloc_new(NULL);
    talloc_free(ctx);
    talloc_free(ctx);

    return 0;
}
