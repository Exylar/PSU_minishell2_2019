/*
** EPITECH PROJECT, 2019
** PSU_my_sh
** File description:
** my_sh
*/

#include "../include/my.h"
#include "../include/my_sh.h"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>

void exec(char *path, char **command, t_list *env)
{
    char *argv[100];
    int wstatus = 0;
    pid_t my_prog;
    int j = 1;
    char **envp = init_env_tab(env->next);

    for (int i = 0; i < 100; i++)
        argv[i] = NULL;
    argv[0] = path;
    for (j = 1; command[j] != 0; j++)
        argv[j] = command[j];
    my_prog = fork();
    if (my_prog == 0) {
        execve(path, argv, envp);
        exit(0);
    } else {
        do {
            waitpid(my_prog, &wstatus, WUNTRACED | WCONTINUED);
            error_programm(wstatus, env);
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
    } env->prev->data = my_nbr_to_str(0);
}

void call_function(char **command, t_list *env)
{
    struct stat file;

    if (my_strcmp(command[0], "env") == 0)
        chech_my_env(command, env->next);
    else if (my_strcmp(command[0], "setenv") == 0)
        check_my_setenv(command, env->next);
    else if (my_strcmp(command[0], "unsetenv") == 0)
        check_my_unsetenv(command, env->next);
    else if (my_strcmp(command[0], "cd") == 0)
        check_my_cd(command, env->next);
    else if (command[0][0] == '.' && command[0][1] == '/')
        my_exec_executable(command, env);
    else if (lstat(command[0], &file) != -1 && file.st_mode & (S_IXUSR) && !((file.st_mode & S_IFMT) == S_IFDIR))
        exec(command[0], command, env->next);
    else if (path(command[0], env) != NULL)
        exec(path(command[0], env), command, env->next);
    else if (my_strcmp(command[0], "exit") == 0)
        my_exit(command, env->next);
    else
        error_message(NOT_FOUND, command[0], env->next);
}

void read_command(t_list *env, t_parse_command *commands)
{
    char **command;
    int fd = 0;
    char *save;
    char buffer[2048];
    struct stat file;

    while (str_is_an_operator(commands->data)) {
        command = my_interpretor(commands->left->data);
        if (my_strcmp(commands->data, "<") == 0) {
            if (stat(command[0], &file) != -1) {
                save = command[0];
                char *command[] = {"cat", save, NULL};
                fd = my_pipe(fd, command, env);
            } else {
                error_message(NO_FILE_DIR, command[0], env->next);
                commands = commands->right;
            }
        }
        else if (my_strcmp(commands->prev->data, ">") == 0 ||
        my_strcmp(commands->prev->data, ">>") == 0)
            redirection_right(command, fd, commands->prev->data);
        else if (my_strcmp(commands->data, ";") == 0) {
            if (fd != 0) {
                fd = my_pipe(fd, command, env);
                read(fd, buffer, 2048);
                my_printf("%s", buffer);
            }
            else
                call_function(command, env);
        }
        else
            fd = my_pipe(fd, command, env);
        commands = commands->right;
    }
    command = my_interpretor(commands->data);
    if (fd != 0) {
        if (my_strcmp(commands->prev->data, ">") == 0 ||
        my_strcmp(commands->prev->data, ">>") == 0)
            redirection_right(command, fd, commands->prev->data);
        else {
            fd = my_pipe(fd, command, env);
            read(fd, buffer, 2048);
            my_printf("%s", buffer);
        }
    }
    else
        call_function(command, env);
    free(command);
}

int my_sh(int argc, char **argv, char **envp)
{
    t_parse_command *commands;
    t_list *env = init_env(envp);
    char *buff;
    int num = 0;
    char *p_buff;

    while (42) {
        buff = malloc(sizeof(char) * 2048);
        p_buff = buff;
        for (int i = 0; i < 2048; i++)
            buff[i] = ' ';
        my_printf("%s$ ", find_env(env->next, "PWD")->data);
        num = read(0, buff, 2048);
        if (num == 0)
            exit(my_atoi(env->data));
        else if (num > 1)
            buff[num - 1] = '\0';
        else
            buff[num] = '\0';
        if (as_alpha_num(buff) == 1) {
            commands = fill_command(buff);
            read_command(env, commands->right);
            free(commands);
        }
        free(p_buff);
    }
}