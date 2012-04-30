#include <talloc.h>
#include "user.h"

int main(int argc, char **argv)
{
    struct user *user = NULL;
    struct user *user2 = NULL;

    user = talloc_zero(NULL, struct user);
    if (user == NULL) {
        goto done;
    }

    user2 = talloc_zero(NULL, struct user);
    if (user2 == NULL) {
        goto done;
    }

    user->username = talloc_strdup(user, "name");

    /*
     * Wrong:
     * user2->username = talloc_steal(user2, user->username);
     */

    /* Good: */
    user2->username = talloc_move(user2, &user->username);

done:
    /* free user */
    talloc_free(user);
    talloc_free(user2);

    return 0;
}
