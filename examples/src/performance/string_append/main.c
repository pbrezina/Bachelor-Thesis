#include <stdlib.h>
#include <stdio.h>

#include "../../common.h"
#include "string_append.h"

int main(int argc, char **argv)
{
    int count = COUNT;
    const char *str = "somestring";

    if (argc > 1) {
        count = atoi(argv[1]);
    }

    if (argc > 2) {
        str = argv[2];
    }

    if (argc > 3) {
        fprintf(stderr, "Usage: %s [num_elements [string]]", argv[0]);
        goto fail;
    }

    printf("Testing malloc strcat...\n");
    test_malloc_strcat(count, str);

    printf("Testing malloc strcat (malloc all)...\n");
    test_malloc_strcat_malloc(count, str);

    printf("Testing malloc strncat...\n");
    test_malloc_strncat(count, str);

    printf("Testing malloc strncat (malloc all)...\n");
    test_malloc_strncat_malloc(count, str);

    printf("Testing malloc memcpy...\n");
    test_malloc_memcpy(count, str);

    printf("Testing malloc memcpy (malloc all)...\n");
    test_malloc_memcpy_malloc(count, str);

    printf("Testing talloc strdup_append...\n");
    test_talloc_append(count, str);

    printf("Testing talloc strdup_append (exact pool)...\n");
    test_talloc_append_exact_pool(count, str);

    printf("Testing talloc strdup_append (guessed pool)...\n");
    test_talloc_append_guess_pool(count, str);

    printf("Testing talloc strdup_append (parent exact pool)...\n");
    test_talloc_append_parent_exact_pool(count, str);

    printf("Testing talloc strdup_append (parent guessed pool)...\n");
    test_talloc_append_parent_guess_pool(count, str);

    printf("Testing talloc strdup_append_buffer...\n");
    test_talloc_append_buffer(count, str);

    printf("Testing talloc strdup_append_buffer (exact pool)...\n");
    test_talloc_append_buffer_exact_pool(count, str);

    printf("Testing talloc strdup_append_buffer (guessed pool)...\n");
    test_talloc_append_buffer_guess_pool(count, str);

    printf("Testing talloc strdup_append_buffer (parent exact pool)...\n");
    test_talloc_append_buffer_parent_exact_pool(count, str);

    printf("Testing talloc strdup_append_buffer (parent guessed pool)...\n");
    test_talloc_append_buffer_parent_guess_pool(count, str);

    return 0;

fail:
    return -1;
}
