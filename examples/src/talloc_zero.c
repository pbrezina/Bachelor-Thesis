#include <talloc.h>
#include "user.h"

int main(int argc, char **argv)
{
    struct user *user = NULL;
    struct user *user_zero = NULL;

    user = talloc(NULL, struct user);
    if (user == NULL) {
        goto done;
    }

    /* initialize to default values */
    user->uid = 0;
    user->username = NULL;
    user->num_groups = 0;
    user->groups = NULL;

    /* or we can achieve the same result with */
    /* or we can achieve the same result with */
    user_zero = talloc_zero(NULL, struct user);
    printf("%d %lu %p %p\n", user_zero->uid,
                             (unsigned long)user_zero->num_groups,
                             user_zero->username, user_zero->groups);

done:
    talloc_free(user);
    talloc_free(user_zero);
    return 0;
}
