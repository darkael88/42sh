#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:59:57 by mdarty            #+#    #+#              #
#    Updated: 2014/02/04 07:57:10 by mdarty           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		libft.a

SRC =		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
			ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
			ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c\
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c\
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putchar_fd.c\
			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
			ft_putstr.c ft_putstr_fd.c ft_splitspace.c ft_strlen.c\
			ft_strclr.c ft_strequ.c ft_strnequ.c get_next_line.c ft_str3join.c\
			ft_str4join.c ft_chrsplit.c ft_memdeltab.c ft_delfulltab.c\
			ft_del_str_tab.c ft_get_str_tab.c ft_tablen.c ft_tabstrdup.c\

CFLAGS =	-Wall -Werror -Wextra -I .

CC =		gcc $(CFLAGS)

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
			$(CC) -c $(CFLAGS) $(SRC)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
