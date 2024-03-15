# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amema <amema@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:09:18 by amema             #+#    #+#              #
#    Updated: 2024/03/15 17:09:20 by amema            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = minishell
LIBFT = lib/libft/libft.a
PRINTF = lib/ft_printf/libftprintf.a

src = \
		src/mini_shell.c\
		src/utils/general_utils.c\
		src/utils/general_utils1.c\
		src/utils/general_utils2.c\
		src/utils/my_free.c\
		src/parser/parser.c\
		src/parser/lexer_list.c\
		src/parser/lexer_list_utils.c\
		src/parser/dollar_expander.c\
		src/parser/path.c\
		src/parser/path_utils.c\
		src/parser/expander_utils.c\
		src/parser/expander_utils1.c\
		src/builtin/my_pwd.c\
		src/builtin/my_env.c\
		src/builtin/my_export.c\
		src/builtin/export_utils.c\
		src/builtin/main_env_n_export.c\
		src/builtin/my_unset.c\
		src/builtin/my_cd.c\
		src/builtin/cd_utils.c\
		src/builtin/cd_utils1.c\
		src/builtin/builtins_utils.c\
		src/builtin/my_echo.c\
		src/builtin/my_exit.c\
		src/executor/built_in_exe.c\
		src/executor/exe_main.c\
		src/executor/exe_utils.c\
		src/executor/redirection_here.c\
		src/executor/redirection_in.c\
		src/executor/redirection_out.c\

OBJ = $(src:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -g

CC = gcc

all: $(NAME)

$(NAME) : $(OBJ)
	make all bonus -C lib/libft
	make -C lib/ft_printf
	$(CC) $(OBJ) $(FLAGS) $(LIBFT) $(PRINTF)  -o minishell -lreadline -lhistory -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include
	@echo "\033[32mho compilato un programma di Antonio Ricci\033[0m"
clean:
	make clean -C lib/libft
	make clean -C lib/ft_printf
	rm -f $(OBJ)
	@echo "\033[33mstriscia?\033[0m"

fclean: clean
	make fclean -C lib/libft
	make fclean -C lib/ft_printf
	rm -f $(NAME)
	@echo "\033[33m .-> la notizia\033[0m"

re: fclean all

.PHONY:		all clean fclean re
