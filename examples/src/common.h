#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>

#ifndef EOK
#define EOK 0
#endif

#define ERRORCHECK(expr, msg, label) do     \
{                                           \
    if ((expr)) {                           \
        fprintf(stderr, msg);               \
        goto label;                         \
    }                                       \
} while (0)

#define ENOMEMCHECK(var, label) \
    ERRORCHECK((var) == NULL, "Out of memory\n", label)

#endif /* COMMON_H_ */
