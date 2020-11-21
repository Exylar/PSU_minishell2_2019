/*
** EPITECH PROJECT, 2019
** pipe
** File description:
** pipe
*/

#include "../include/my.h"
#include "../include/my_sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int my_pipe(int fdd, char **command, t_list *env)
{
    int fd[2];
    pid_t pid;

    pipe(fd);
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        dup2(fdd, 0);
        dup2(fd[1], 1);
        close(fd[0]);
        call_function(command, env);
        close(fd[1]);
        exit(0);
    } else {
        wait(NULL);
        close(fd[1]);
        fdd = fd[0];
    }
    return fdd;
}