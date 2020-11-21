/*
** EPITECH PROJECT, 2019
** exit
** File description:
** exit
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>

void my_exit(char **command, t_list *env)
{
    if (!command[1])
        exit(0);
    if (!(command[1][0] >= '0' && command[1][0] <= '9'))
        error_message(EXPR_SYN, command[0], env);
    else if (!my_str_isnum(command[1]))
        error_message(BAD_FORMAT, command[0], env);
    else
        exit(my_atoi(command[1]));
}