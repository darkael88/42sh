/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 20:53:58 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 18:31:27 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include "shell.h"
#include "struct.h"
#include <stdlib.h>

void	write_command(char *cmd)
{
	(void)cmd;
}

void	empty_command_line(void)
{
	int		i;

	i = 0;
	while (i < get_num_cols())
	{
		tputs(tgetstr("le", NULL), 1, t_write);
		i++;
	}
	tputs(tgetstr("nd", NULL), 1, t_write);
	tputs(tgetstr("nd", NULL), 1, t_write);
	tputs(tgetstr("nd", NULL), 1, t_write);
	tputs(tgetstr("ce", NULL), 1, t_write);
}

void	clear_command_line(t_char *list)
{
	int		i;
	int		j;
	int		numcols;

	numcols = get_num_cols();
	j = 0;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	tputs(tgetstr("rc", NULL), 1, t_write);
	while (j <= (i + 3) / numcols)
	{
		tputs(tgetstr("ce", NULL), 1, t_write);
		if ((i + 3) > ((j + 1) * numcols))
			tputs(tgetstr("do", NULL), 1, t_write);
		j++;
	}
	tputs(tgetstr("rc", NULL), 1, t_write);
}

void	refresh_command_line(t_char **list)
{
	t_char	*temp;
	t_char	**activechar;
	int		i;
	char	*tempstr;

	cursor_move_left(*(getcurpos()));
	tputs(tgetstr("cd", NULL), 1, t_write);
	activechar = getactivechar();
	ft_putstr_fd("$> ", *(gettty()));
	if (*list)
	{
		tempstr = char_to_str((*list)->next);
		*(getcurpos()) = 3 + ft_strlen(tempstr);
		ft_putstr_fd(tempstr, *(gettty()));
		ft_memdel((void **)&tempstr);
		temp = (*list)->next;
		i = 3;
		while (temp && temp != *activechar)
		{
			i++;
			temp = temp->next;
		}
		cursor_move_left(*(getcurpos()) - i);
	}
}
