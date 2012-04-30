#include <talloc.h>
#include <string.h>

size_t talloc_strlen(const char *str)
{
    return talloc_array_length(str) - 1;
}

int main(int argc, char **argv)
{
    char *str = NULL;
    char *str2 = NULL;

    str = talloc_strdup(NULL, "hello world");
    if (str == NULL) {
        goto done;
    }

    str2 = talloc_strdup(NULL, "hello world");
    if (str2 == NULL) {
        goto done;
    }

    str2[5] = '\0';
    printf("%lu\n", talloc_strlen(str));
    printf("%lu\n", talloc_strlen(str2));
    printf("%lu\n", strlen(str2));

done:
    talloc_free(str);
    talloc_free(str2);
    return 0;
}
