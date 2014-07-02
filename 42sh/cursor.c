/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 22:49:03 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:07:15 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include "shell.h"

void	cursor_go_to(int num)
{
	int		i;
	int		numcols;
	int		numlines;

	numcols = get_num_cols();
	numlines = num / numcols;
	numcols = num % numcols;
	i = 0;
	while (i < numlines)
	{
		tputs(tgetstr("do", NULL), 1, t_write);
		i++;
	}
	i = 0;
	while (i < numcols)
	{
		tputs(tgetstr("nd", NULL), 1, t_write);
		i++;
	}
}

void	cursor_move_right(int num)
{
	int		numcols;
	int		*curpos;

	numcols = get_num_cols();
	curpos = getcurpos();
	num += *curpos;
	while (*curpos < num)
	{
		(*curpos)++;
		if (*curpos % numcols == 0)
			tputs(tgetstr("do", NULL), 1, t_write);
		else
			tputs(tgetstr("nd", NULL), 1, t_write);
	}
}

void	cursor_move_left(int num)
{
	int		numcols;
	int		*curpos;

	numcols = get_num_cols();
	curpos = getcurpos();
	num = *curpos - num;
	while (*curpos > num)
	{
		if ((*curpos - 1) % numcols == 0 && *curpos > 0)
		{
			tputs(tgetstr("up", NULL), 1, t_write);
			*curpos -= numcols;
			cursor_move_right(numcols - 1);
			(*curpos)++;
		}
		else
			tputs(tgetstr("le", NULL), 1, t_write);
		(*curpos)--;
	}
}
