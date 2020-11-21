/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** env
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>

t_list *create_node(void)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    node->data = my_nbr_to_str(0);
    node->prev = node;
    node->next = node;
    return node;
}

void *add_env(t_list *env, char *name, char *data)
{
    t_list *tmp;

    tmp = create_node();
    tmp->name = my_strdup(name);
    tmp->data = my_strdup(data);
    tmp->next = 0;
    tmp->prev = env->prev;
    env->prev->next = tmp;
    env->prev = tmp;
}

t_list *find_env(t_list *env, char *to_find)
{
    if (my_strcmp(env->name, to_find) == 0)
        return env;
    if (env->next != 0)
        find_env(env->next, to_find);
    else
        return NULL;
}

char *get_name(char *env, char **name, char **data)
{
    int i = 0;

    while (env[i] != '=') {
        i++;
    }
    name[0] = malloc(sizeof(char) * i + 1);
    name[0] = my_strncpy(name[0], env, i);
    while (env[0] != '=')
        env++;
    env++;
    data[0] = my_strdup(env);
}

t_list *init_env(char **envp)
{
    char *name;
    char *data;
    t_list *tmp;
    t_list *tmp2;

    tmp = create_node();
    for (int i = 0; envp[i] != NULL; i++) {
        get_name(envp[i], &name, &data);
        tmp2 = create_node();
        tmp2->name = my_strdup(name);
        tmp2->data = my_strdup(data);
        tmp2->prev = tmp->prev;
        tmp2->next = tmp;
        tmp->prev->next = tmp2;
        tmp->prev = tmp2;
        if (envp[i + 1] == NULL)
            tmp2->next = 0;
        free(name);
        free(data);
    }
    return tmp;
}