/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhits2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 23:02:00 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:25:11 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include "shell.h"
#include "struct.h"

int		key_delete(t_char **list, char **envp)
{
	t_char	*temp;
	t_char	**activechar;

	(void)envp;
	activechar = getactivechar();
	if (!(*list) || (*list && *activechar == (*list)->next))
		return (1);
	if (!(*activechar))
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
	}
	else
		temp = (*activechar)->prev;
	*activechar = char_delete(list, temp);
	cursor_move_left(1);
	tputs(tgetstr("im", NULL), 1, t_write);
	tputs(tgetstr("dc", NULL), 1, t_write);
	tputs(tgetstr("ei", NULL), 1, t_write);
	return (1);
}

int		key_alt_right(t_char **list, char **envp)
{
	t_char	**active;

	active = getactivechar();
	(void)envp;
	if (!(*active) || !(*list))
		return (1);
	while (*active && (*active)->c != ' ' && (*active)->c != '\t')
	{
		*active = (*active)->next;
		cursor_move_right(1);
	}
	while (*active && ((*active)->c == ' ' || (*active)->c == '\t'))
	{
		*active = (*active)->next;
		cursor_move_right(1);
	}
	return (1);
}

int		key_alt_left(t_char **list, char **envp)
{
	t_char	**active;

	(void)envp;
	if (*list == NULL || (*list)->next == NULL)
		return (1);
	active = move_active_char_back(list);
	if (*active == NULL)
		return (1);
	while (*active != *list && ((*active)->c == ' ' || (*active)->c == '\t'))
	{
		*active = (*active)->prev;
		cursor_move_left(1);
	}
	while (*active != *list && (*active)->c != ' ' && (*active)->c != '\t')
	{
		*active = (*active)->prev;
		cursor_move_left(1);
	}
	*active = (*active)->next;
	cursor_move_right(1);
	return (1);
}

int		key_home(t_char **list, char **envp)
{
	t_char	*temp;

	(void)envp;
	if (*list)
	{
		move_active_char_back(list);
		temp = *(getactivechar());
		while (temp && temp->prev && temp->prev && temp->prev != *list)
		{
			cursor_move_left(1);
			temp = temp->prev;
		}
		*(getactivechar()) = temp;
	}
	return (1);
}

int		key_end(t_char **list, char **envp)
{
	t_char	*temp;

	(void)envp;
	if (*list)
	{
		temp = *(getactivechar());
		while (temp)
		{
			cursor_move_right(1);
			temp = temp->next;
		}
		*(getactivechar()) = NULL;
	}
	return (1);
}
