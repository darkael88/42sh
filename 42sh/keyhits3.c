/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhits3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 22:34:05 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:25:26 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include "shell.h"
#include "struct.h"

static void		reverse_activechar(t_char *activechar, int flag)
{
	if (activechar == NULL)
		return ;
	if (flag == 1)
	{
		tputs(tgetstr("mr", NULL), 1, t_write);
		write(*(gettty()), &(activechar->c), 1);
		tputs(tgetstr("me", NULL), 1, t_write);
	}
	else
		write(*(gettty()), &(activechar->c), 1);
	*(getcurpos()) += 1;
	cursor_move_left(1);
}

static void		select_right(t_char **activechar)
{
	t_copy	*cp;

	cp = getcp();
	if (*activechar && *activechar != cp->left)
		reverse_activechar(*activechar, 1);
	else if (*activechar && *activechar == cp->left)
		reverse_activechar(*activechar, 0);
	cp_refresh(*activechar);
	*activechar = (*activechar)->next;
	cp_refresh(*activechar);
	cursor_move_right(1);
}

static void		select_left(t_char **activechar)
{
	t_copy	*cp;

	cp = getcp();
	if (*activechar && *activechar == cp->right)
		reverse_activechar(*activechar, 0);
	cp_refresh(*activechar);
	*activechar = (*activechar)->prev;
	cp_refresh(*activechar);
	cursor_move_left(1);
	if (*activechar && *activechar != cp->right)
		reverse_activechar(*activechar, 1);
}

int				key_shift_right(t_char **list, char **envp)
{
	t_char	**activechar;

	(void)list;
	(void)envp;
	activechar = getactivechar();
	if (!(*activechar))
		return (1);
	select_right(activechar);
	return (1);
}

int				key_shift_left(t_char **list, char **envp)
{
	t_char	**activechar;
	t_char	*temp;

	(void)envp;
	if (!(*list))
		return (1);
	activechar = getactivechar();
	if (!(*activechar))
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		if (*list && temp != *list)
		{
			select_left(&temp);
		}
	}
	else if ((*activechar)->prev && (*activechar)->prev != *list)
	{
		select_left(activechar);
	}
	return (1);
}
