/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 20:19:48 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:17:02 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>
#include <termcap.h>
#include "shell.h"
#include "struct.h"

t_term	*getterm(void)
{
	static t_term	term;

	return (&term);
}

int		t_write(int c)
{
	write(*(gettty()), &c, 1);
	return (1);
}

void	term_initiate(void)
{
	char	buffer[2048];
	t_term	term;

	if (tgetent(buffer, getenv("TERM")) < 1)
	{
		ft_putstr_fd("Error : Env not found\n", 2);
		exit(1);
	}
	tcgetattr(0, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	tcsetattr(0, 0, &term);
}

int		term_terminate(t_char **list, char **envp)
{
	t_term	term;

	(void)list;
	(void)envp;
	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	exit(0);
	return (1);
}

void	term_reset(void)
{
	t_term	term;

	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
}
