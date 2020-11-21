/*
** EPITECH PROJECT, 2019
** operator
** File description:
** operator
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"

int str_is_an_operator(char *str)
{
    if (my_strcmp(";", str) == 0 || my_strcmp("|", str) == 0 ||
        my_strcmp("<", str) == 0 || my_strcmp("<<", str) == 0 ||
        my_strcmp(">", str) == 0 || my_strcmp(">>", str) == 0)
        return 1;
    return 0;
}

int is_an_operator(char c)
{
    if (c == ';' || c == '|' || c == '<' || c == '>')
        return 1;
    return 0;
}