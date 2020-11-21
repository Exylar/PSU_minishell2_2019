/*
** EPITECH PROJECT, 2019
** cd
** File description:
** cd
*/

#include "../../include/my.h"
#include "../../include/my_sh.h"
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void check_my_cd(char **command, t_list *env)
{
    char *oldpass = find_env(env, "OLDPWD")->data;

    if (command[2] != 0)
        error_message(TOO_ARG, command[0], env);
    else if (command[1] != 0) {
        if (my_strcmp(command[1], "-") == 0) {
            my_printf("%s\n", oldpass);
            my_cd(oldpass, env);
        } else
            my_cd(command[1], env);
    }
    else
        my_cd(find_env(env, "HOME")->data, env);
}

void my_cd(char *path, t_list *env)
{
    char my_cwd[2048];
    char *cpy_path = my_strdup(find_env(env, "PWD")->data);
    DIR *dir = opendir(path);
    struct stat file;

    if (lstat(path, &file) == -1)
        error_message(NO_FILE_DIR, path, env);
    else if (dir == NULL) {
        if (errno == EACCES)
            error_message(PERM_DENIED, path, env);
        else
            error_message(NOT_DIR, path, env);
    } else {
        chdir(path);
        getcwd(my_cwd, 2048);
        my_setenv(env, "PWD", my_cwd);
        my_setenv(env, "OLDPWD", cpy_path);
        env->prev->data = my_nbr_to_str(1);
    }
    free(cpy_path);
    closedir(dir);
}