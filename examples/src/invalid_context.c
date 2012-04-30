#include <talloc.h>
#include <string.h>

int main(int argc, char **argv)
{
    talloc_set_log_stderr();
    TALLOC_CTX *ctx = talloc_new(NULL);
    char *str = strdup("not a talloc context");
    talloc_steal(ctx, str);

    return 0;
}
