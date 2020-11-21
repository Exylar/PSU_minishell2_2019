/*
** EPITECH PROJECT, 2019
** PSU_my_sh
** File description:
** interpretor
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>

char *remove_space(char *command)
{
    while (command[0] == ' ' || command[0] == '\t')
        command++;
    return command;
}

void add_str(char ***my_parsed_commande, char **str, int count)
{
    my_parsed_commande[0] = my_realloc(my_parsed_commande[0],
    sizeof(char *) * (count + 1), sizeof(char *) * (count + 3));
    my_parsed_commande[0][count] = my_strdup(str[0]);
    my_parsed_commande[0][count + 1] = NULL;
}

char **my_interpretor(char *command)
{
    char **my_parsed_commande = malloc(sizeof(char *));
    char *str = malloc(sizeof(char) * my_strlen(command) + 1);
    int j = 0;
    int count = 0;

    command = remove_space(command);
    for (command; command[0] != '\0'; command++) {
        if (command[0] == ' ' || command[0] == '\t') {
            if (as_alpha_num(str)) {
                add_str(&my_parsed_commande, &str, count);
                command = remove_space(command);
                command--;
                count++;
                j = 0;
            }
        } else {
            str[j++] = command[0];
            str[j] = '\0';
        }
    }
    if (j != 0)
        add_str(&my_parsed_commande, &str, count);
    return my_parsed_commande;
}