#include <talloc.h>
#include "user.h"

int main(int argc, char **argv)
{
    TALLOC_CTX *ctx = NULL;
    struct user *user = NULL;
    struct user *user_zero = NULL;

    /* new zero-length top level context */
    ctx = talloc_new(NULL);
    if (ctx == NULL) {
        goto done;
    }

    user = talloc(ctx, struct user);
    if (user == NULL) {
        goto done;
    }

    /* initialize to default values */
    user->uid = 0;
    user->username = NULL;
    user->num_groups = 0;
    user->groups = NULL;

    /* or we can achieve the same result with */
    user_zero = talloc_zero(ctx, struct user);
    printf("%d %lu %p %p\n", user_zero->uid,
                             (unsigned long)user_zero->num_groups,
                             user_zero->username, user_zero->groups);

done:
    /* easy to free */
    talloc_free(ctx);
    return 0;
}
