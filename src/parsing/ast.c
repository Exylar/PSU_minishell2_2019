/*
** EPITECH PROJECT, 2019
** ast_parse_commande
** File description:
** ast
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>
#include <stdio.h>

t_parse_command *create_node_commande(void)
{
    t_parse_command *node;
    node = malloc(sizeof(t_parse_command) + 1);
    node->data = NULL;
    node->prev = node;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void *get_operator(char *commande, int *value, char **operator)
{
    if (commande[value[0] + 1] == commande[value[0]]) {
        operator[0][0] = commande[value[0]];
        operator[0][1] = commande[value[0] + 1];
        operator[0][2] = '\0';
        value[0]++;
    } else {
        operator[0][0] = commande[value[0]];
        operator[0][1] = '\0';
    }
}

void *fill_node(t_parse_command *command, char *type, char *data)
{
    t_parse_command *new_node;

    if (my_strcmp(type, "LEFT") == 0) {
        new_node = create_node_commande();
        new_node->data = my_strdup(data);
        new_node->prev = command->prev;
        command->prev->left = new_node;
    } else if (my_strcmp(type, "RIGHT") == 0) {
        new_node = create_node_commande();
        new_node->prev = command->prev;
        new_node->data = my_strdup(data);
        command->prev->right = new_node;
        command->prev = new_node;
    }
}

t_parse_command *fill_command(char *commande)
{
    t_parse_command *command;
    char *operator = malloc(sizeof(char) * 3);
    char memory[256];
    char memory2[256] = {'0'};
    int value[2] = {0, 0};

    command = create_node_commande();
    command->data = "";
    for (value[0]; commande[value[0]] != '\0'; value[0]++) {
        if (is_an_operator(commande[value[0]])) {
            get_operator(commande, value, &operator);
            if (my_strcmp("<", operator) == 0 || my_strcmp("<<", operator) == 0) {
                if (memory2[0] != '0')
                    fill_node(command, "LEFT", memory);
                else
                    my_strcpy(memory2, memory);
                fill_node(command, "RIGHT", operator);
            }
            else {
                if (memory2[0] != '0') {
                    fill_node(command, "LEFT", memory);
                    fill_node(command, "RIGHT", operator);
                    fill_node(command, "LEFT", memory2);
                    memory2[0] = '0';
                }
                else {
                    fill_node(command, "RIGHT", operator);
                    fill_node(command, "LEFT", memory);
                }
            }
            value[0]++;
            value[1] = 0;
        }
        memory[value[1]] = commande[value[0]];
        memory[value[1] + 1] = '\0';
        value[1]++;
    } if (memory2[0] == '0')
        fill_node(command, "RIGHT", memory);
    else if (memory2[0] != '0') {
        fill_node(command, "LEFT", memory);
        fill_node(command, "RIGHT", memory2);
    }
    free(operator);
    return command;
}