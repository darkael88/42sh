#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 13:06:39 by dbenoit           #+#    #+#              #
#    Updated: 2014/03/27 22:10:45 by dbenoit          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

SRC = \
	main.c \
	tools.c \
	tools2.c \
	tools3.c \
	tools4.c \
	tools5.c \
	term.c \
	tty.c \
	command2.c \
	keyhits.c \
	keyhits2.c \
	keyhits3.c \
	keyhits4.c \
	keys.c \
	copypaste.c \
	sig.c \
	list.c \
	list2.c \
	env.c \
	listenv.c \
	history.c \
	cursor.c \
	ft_strglue.c \
	ft_strndup.c \
	ft_parse.c \
	ft_check_error_parse.c \
	ft_parse_cut.c \
	ft_parse_tlist.c \
	ft_parse_del_tlist.c \
	ft_error_parse.c \
	ft_separate_op.c \
	ft_separate_pipe.c \
	ft_separate_tpoint.c \
	ft_send_parse_cmd.c \
	ft_cd.c \
	ft_cd_home.c \
	ft_cd_least.c \
	ft_cd_tild.c \
	ft_error_cd.c \
	ft_other_cd.c \
	ft_echo.c \
	pipe.c \
	redir.c \
	command.c \
	ft_parse_red.c \
	ft_arg_env_parse.c \
	ft_unset_env.c \
	ft_parse_status_zero.c \
	ft_setenv.c \
	ft_echo_tool.c \
	ft_echo_end.c \
	ft_check_error_parse_red.c \
	test_alone.c \
	process_command.c \
	builtin.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -L/usr/lib -ltermcap -Llibft -lft -o $(NAME) $(OBJ)

%.o: %.c
	gcc -Wall -Wextra -Werror -I . -I libft -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make re -C libft
	make all

test: fclean
	gcc -Wall -Wextra -Werror -I . -I libft -g -c $(SRC)
	gcc -g -L/usr/lib -ltermcap -Llibft -lft -o $(NAME) $(OBJ)
