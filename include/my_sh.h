/*
** EPITECH PROJECT, 2019
** my_sh
** File description:
** my_sh
*/

typedef struct s_list
{
    char *name;
    char *data;
    struct s_list *prev;
    struct s_list *next;
} t_list;

typedef struct s_parse_command
{
    void *data;
    struct s_parse_command *prev;
    struct s_parse_command *left;
    struct s_parse_command *right;
} t_parse_command;

enum error{NOT_FOUND, NO_FILE_DIR, TOO_ARG, FEW_ARG,
    PERM_DENIED, NOT_DIR, EXPR_SYN, BAD_FORMAT, ONLY_ALPHA};

#ifndef MY_SH_H
#define MY_SH_H

void exec(char *path, char **command, t_list *env);
void call_function(char **command, t_list *env);
void read_command(t_list *env, t_parse_command *commands);
int my_sh(int argc, char **argv, char **envp);

t_parse_command *create_node_commande(void);
void *get_operator(char *commande, int *value, char **operator);
void *fill_node(t_parse_command *command, char *type, char *data);
t_parse_command *fill_command(char *commande);

int str_is_an_operator(char *str);
int is_an_operator(char c);

char *remove_space(char *command);
void add_str(char ***my_parsed_commande, char **str, int count);
char **my_interpretor(char *command);

void error_programm(int wstatus, t_list *env);
void such_file_with_param(char *str, char *param, t_list *env);
void error_message(int error, char *str, t_list *env);

int my_pipe(int fdd, char **command, t_list *env);
int redirection_right(char **com, int fd, char *operator);

t_list *create_node(void);
void *add_env(t_list *env, char *name, char *data);
t_list *find_env(t_list *env, char *to_find);
char *get_name(char *env, char **name, char **data);
t_list *init_env(char **envp);

void my_cd(char *path, t_list *env);
void check_my_cd(char **command, t_list *env);

void chech_my_env(char **command, t_list *env);
void my_env(t_list *env);

void my_exec_executable(char **command, t_list *env);

void my_exit(char **command, t_list *env);

char *path(char *command, t_list *env);
int check_path(char *path);

void check_my_setenv(char **command, t_list *env);
void my_setenv(t_list *env, char *name, char *data);

void check_my_unsetenv(char **command, t_list *env);
void my_unsetenv(t_list *env, char *name);

char **init_env_tab(t_list *env);

#endif
