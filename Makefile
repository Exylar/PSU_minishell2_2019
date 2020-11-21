##
## EPITECH PROJECT, 2019
## PSU_minishell_bootstrap
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_sh.c	\
		src/builtins/cd.c	\
		src/builtins/env.c	\
		src/builtins/executable.c	\
		src/builtins/exit.c	\
		src/builtins/setenv.c	\
		src/builtins/unsetenv.c	\
		src/builtins/path.c	\
		src/environement/env.c	\
		src/environement/env_tab.c	\
		src/message_error/error.c	\
		src/manipulations/pipe.c	\
		src/manipulations/redirections.c	\
		src/parsing/ast.c	\
		src/parsing/interpretor.c	\
		src/parsing/operator.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy
	make -C lib/my clean

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
