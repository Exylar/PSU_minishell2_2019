/*
** EPITECH PROJECT, 2019
** env_tab
** File description:
** env_tab
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>

char **init_env_tab(t_list *env)
{
    char **envp = malloc(sizeof(char *));
    char *my_env;
    int i = 0;
    int count = 0;

    for (i; env != NULL; i++) {
        my_env = malloc(sizeof(char) * 2048);
        my_env = my_strcpy(my_env, env->name);
        my_env = my_strcat(my_env, "=");
        my_env = my_strcat(my_env, env->data);
        envp = my_realloc(envp, sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
        envp[i] = my_strdup(my_env);
        envp[i + 1] = NULL;
        free(my_env);
        env = env->next;
    }
    return envp;
}