/*
** EPITECH PROJECT, 2019
** env
** File description:
** env
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"

void chech_my_env(char **command, t_list *env)
{
    if (command[1])
        such_file_with_param(command[0], command[1], env);
    else {
        my_env(env);
        env->prev->data = my_nbr_to_str(0);
    }
}

void my_env(t_list *env)
{
    my_printf("%s=", env->name);
    my_printf("%s\n", env->data);
    if (env->next != 0)
        my_env(env->next);
}

