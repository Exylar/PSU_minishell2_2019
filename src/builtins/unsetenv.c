/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** unsetenv
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>

void check_my_unsetenv(char **command, t_list *env)
{
    int j = 1;

    if (!command[1])
        error_message(FEW_ARG, command[0], env);
    while (command[j]) {
        my_unsetenv(env, command[j]);
        j++;
        env->prev->data = my_nbr_to_str(0);
    }
}

void my_unsetenv(t_list *env, char *name)
{
    t_list *tmp;

    tmp = find_env(env->next, name);
    if (tmp != NULL) {
        if (tmp->next != NULL) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            env->prev->prev = tmp->next;
        } else {
            tmp->prev->next = 0;
            env->prev = tmp->prev;
        }
        free(tmp->name);
        free(tmp->data);
        free(tmp);
    }
}