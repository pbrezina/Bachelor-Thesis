#ifndef USER_H_
#define USER_H_

struct user {
    uid_t uid;
    char *username;
    size_t num_groups;
    char **groups;
};

#endif /* USER_H_ */
