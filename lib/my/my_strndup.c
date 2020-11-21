/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup
*/

#include "stdlib.h"
#include "my.h"

char *my_strndup(char const *src, int size)
{
    char *str_new;

    str_new = malloc(sizeof(char) * (size + 1));
    str_new = my_strncpy(str_new, src, size);
    return (str_new);
}