#include "shell.h"
#include <string.h>

char *shell_getenv(const char *name, char **envp) {
    size_t name_len;

    if (name == NULL || envp == NULL) {
        return NULL;
    }

    name_len = strlen(name);

    {
        int i;
        for (i = 0; envp[i] != NULL; i++) {
            if (strncmp(name, envp[i], name_len) == 0 && envp[i][name_len] == '=') {
                /* Return the value part of the environment variable */
                return envp[i] + name_len + 1;
            }
        }
    }

    /* If no match is found, return NULL */
    return NULL;
}
