#include <talloc.h>

struct foo {
    char *str;
};

int main(int argc, char **argv)
{
    TALLOC_CTX *ctx = NULL;
    struct foo *foo = NULL;
    char *str = NULL;
    char *str2 = NULL;

    ctx = talloc_new(NULL);
    if (ctx == NULL) {
        goto done;
    }

    str = talloc_strdup(ctx, "my string");
    if (str == NULL) {
        goto done;
    }

    foo = talloc_zero(ctx, struct foo);
    if (foo == NULL) {
        goto done;
    }

    foo->str = talloc_strdup(foo, "I am Foo");
    if (foo->str == NULL) {
        goto done;
    }

    str2 = talloc_strdup(foo, "Foo is my parent");
    if (str2 == NULL) {
        goto done;
    }

    /* print full report */
    talloc_report_full(ctx, stdout);

done:
    talloc_free(ctx);
    return 0;
}
