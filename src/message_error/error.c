/*
** EPITECH PROJECT, 2019
** error_1
** File description:
** error_1
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void error_programm(int wstatus, t_list *env)
{
    if (WTERMSIG(wstatus) != 0)
        my_printf("%s\n", strsignal(WTERMSIG(wstatus)));
    env->prev->data = my_nbr_to_str(WTERMSIG(wstatus));
}

void such_file_with_param(char *str, char *param, t_list *env)
{
    my_printf("%s: ‘%s’: No such file or directory\n", str, param);
    env->prev->data = my_nbr_to_str(1);
}

void error_message(int error, char *str, t_list *env)
{
    if (error == 0)
        my_printf("%s: Command not found.\n", str);
    if (error == 1)
        my_printf("%s: No such file or directory.\n", str);
    if (error == 2)
        my_printf("%s: too many arguments\n", str);
    if (error == 3)
        my_printf("%s: Too few arguments.\n", str);
    if (error == 4)
        my_printf("%s: Permission denied.\n", str);
    if (error == 5)
        my_printf("%s: Not a directory.\n", str);
    if (error == 6)
        my_printf("%s: Expression Syntax.\n", str);
    if (error == 7)
        my_printf("%s: Badly formed number.\n", str);
    if (error == 8)
        my_printf("%s: Variable name must contain "
        "alphanumeric characters.\n", str);
    env->prev->data = my_nbr_to_str(1);
}