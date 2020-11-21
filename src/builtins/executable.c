/*
** EPITECH PROJECT, 2019
** exec
** File description:
** exec
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void my_exec_executable(char **command, t_list *env)
{
    struct stat file;

    if (lstat(command[0], &file) != -1 && file.st_mode & (S_IXUSR) &&
    !((file.st_mode & S_IFMT) == S_IFDIR)) {
        exec(command[0], command, env);
        env->prev->data = my_nbr_to_str(0);
    } else if ((file.st_mode & S_IFMT) == S_IFDIR)
        error_message(PERM_DENIED, command[0], env);
    else
        error_message(NOT_FOUND, command[0], env);
}