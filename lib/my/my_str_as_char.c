/*
** EPITECH PROJECT, 2019
** my_str_as_alphanum
** File description:
** my_str_as_alphanum
*/

int as_alpha_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 33)
            return 1;
    }
    return 0;
}