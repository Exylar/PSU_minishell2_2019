/*
** EPITECH PROJECT, 2019
** my_str_isalphanum
** File description:
** my_str_isalphanum
*/

int my_str_isalphanum(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] < '9')))
            return 0;
    }
    return 1;
}