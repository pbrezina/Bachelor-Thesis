#include <talloc.h>
#include "user.h"

int main(int argc, char **argv)
{
    struct user *user = NULL;
    int i;

    /* create new top level context */
    user = talloc(NULL, struct user);
    if (user == NULL) {
        goto done;
    }

    user->uid = 1000;
    user->num_groups = 10;

    /* make user the parent of following contexts */
    user->username = talloc_strdup(user, "Test user");
    if (user->username == NULL) {
        goto done;
    }

    user->groups = talloc_array(user, char*, user->num_groups);
    if (user->groups == NULL) {
        goto done;
    }


    for (i = 0; i < user->num_groups; i++) {
        /* make user->groups the parent of following context */
        user->groups[i] = talloc_asprintf(user->groups,
                                          "Test group %d", i);
        if (user->groups[i] == NULL) {
            goto done;
        }
    }

done:
    /* free user */
    talloc_free(user);

    return 0;
}
