/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            return dest;
    }
    dest[i] = '\0';
    return dest;
}