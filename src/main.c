/*
** EPITECH PROJECT, 2019
** PSU_minishell_bootstrap
** File description:
** main
*/

#include "../include/my.h"
#include "../include/my_sh.h"
#include <stdio.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
    return my_sh(argc, argv, envp);
}