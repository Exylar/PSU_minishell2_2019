/*
** EPITECH PROJECT, 2019
** path
** File description:
** path
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>

int check_path(char *path)
{
    struct stat file;

    if (lstat(path, &file) != -1 && file.st_mode & (S_IXUSR))
        return 1;
    return 0;
}

char *path(char *command, t_list *env) {
    char *data;
    char *path = malloc(sizeof(char) * 2048);
    int j = 0;
    int value = 0;

    if (find_env(env->next, "PATH") != NULL)
        data = my_strdup(my_strdup(find_env(env->next, "PATH")->data));
    else
        data = my_strdup("/usr/bin");
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == ':') {
            i++;
            path = my_strcat(path, "/");
            path = my_strcat(path, command);
            j = 0;
            value = 1;
        }
        if (check_path(path) == 1 && value)
            return path;
        else
            value = 0;
        path[j++] = data[i];
        path[j] = '\0';
    }
    if (as_alpha_num(path)) {
        path = my_strcat(path, "/");
        path = my_strcat(path, command);
        if (check_path(path) == 1)
            return path;
    }
    return NULL;
}