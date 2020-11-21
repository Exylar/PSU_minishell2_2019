/*
** EPITECH PROJECT, 2019
** setenv
** File description:
** setenv
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>

void check_my_setenv(char **command, t_list *env)
{
    if (!command[1]) {
        my_env(env);
        env->prev->data = my_nbr_to_str(1);
    }
    else if (command[3])
        error_message(TOO_ARG, command[0], env);
    else if (command[1] && !command[2]) {
        if (!my_str_isalphanum(command[1]))
            error_message(ONLY_ALPHA, command[0], env);
        else
            my_setenv(env, command[1], "");
    }
    else if (command[1] && command[2])
        my_setenv(env, command[1], command[2]);
}

void my_setenv(t_list *env, char *name, char *data)
{
    t_list *tmp;

    tmp = find_env(env, name);
    if (tmp == NULL)
        add_env(env->prev, name, data);
    else {
        free(tmp->data);
        tmp->data = my_strdup(data);
    }
    env->prev->data = my_nbr_to_str(0);
}