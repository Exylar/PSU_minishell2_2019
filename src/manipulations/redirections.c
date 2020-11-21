/*
** EPITECH PROJECT, 2019
** redirections
** File description:
** redirections
*/

#include "../include/my.h"
#include "../include/my_sh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int redirection_right(char **com, int fd, char *operator)
{
    int file = 0;
    char *buff[2048];
    int num = 0;

    if (my_strcmp(operator, ">") == 0)
        file = open(com[0], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    else
        file = open(com[0], O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
    num = read(fd, buff, 2048);
    write(file, buff, num);
    close(file);
    return 0;
}