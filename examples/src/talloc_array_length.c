#include <talloc.h>

int main(int argc, char **argv)
{
    TALLOC_CTX *ctx = NULL;
    int *i = NULL;
    char *str = NULL;
    int *array = NULL;

    ctx = talloc_new(NULL);
    if (ctx == NULL) {
        goto done;
    }

    i = talloc_zero(ctx, int);
    if (i == NULL) {
        goto done;
    }

    str = talloc_strdup(ctx, "hello world");
    if (str == NULL) {
        goto done;
    }

    array = talloc_array(ctx, int, 10);
    if (array == NULL) {
        goto done;
    }

    printf("%lu\n", (unsigned long)talloc_array_length(ctx));
    printf("%lu\n", (unsigned long)talloc_array_length(i));
    printf("%lu\n", (unsigned long)talloc_array_length(str));
    printf("%lu\n", (unsigned long)talloc_array_length(array));

done:
    talloc_free(ctx);
    return 0;
}
