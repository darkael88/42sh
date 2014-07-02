/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 21:04:40 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 18:15:23 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termios.h>
#include <termcap.h>
#include "shell.h"
#include "struct.h"

int		key_right(t_char **list, char **envp)
{
	t_char	**activechar;

	(void)list;
	(void)envp;
	activechar = getactivechar();
	if (!(*activechar))
		return (1);
	*activechar = (*activechar)->next;
	cursor_move_right(1);
	if (cp_reset(0))
		refresh_command_line(list);
	return (1);
}

int		key_left(t_char **list, char **envp)
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
			*activechar = temp;
		if (*list && temp != *list)
			cursor_move_left(1);
	}
	else if ((*activechar)->prev && (*activechar)->prev != *list)
	{
		*activechar = (*activechar)->prev;
		cursor_move_left(1);
	}
	if (cp_reset(0))
		refresh_command_line(list);
	return (1);
}

int		key_up(t_char **list, char **envp)
{
	t_char	**history;
	t_char	**active;
	int		i;

	i = 0;
	(void)envp;
	*getactivechar() = NULL;
	history = gethistory();
	active = getactivehistory();
	if (*active == NULL)
		i = -1;
	else
	{
		while (history[i] != *active && i < (MAXHISTORY - 1))
			i++;
	}
	if (i < (MAXHISTORY - 1))
		*active = history[i + 1];
	else
		*active = history[0];
	char_wipe(list);
	*list = char_dup(*active);
	refresh_command_line(list);
	return (1);
}

int		key_down(t_char **list, char **envp)
{
	t_char	**history;
	t_char	**active;
	int		i;

	i = 1;
	(void)envp;
	history = gethistory();
	active = getactivehistory();
	if (*active == NULL)
		return (1);
	*getactivechar() = NULL;
	while (history[i] != *active && i < MAXHISTORY)
		i++;
	if (*active == history[0])
	{
		char_wipe(list);
		*list = char_new('-');
		*active = NULL;
	}
	if (i < MAXHISTORY)
		*active = history[i - 1];
	if (i < MAXHISTORY)
		*list = char_dup(*active);
	refresh_command_line(list);
	return (1);
}

int		key_enter(t_char **list, char **envp)
{
	char	*parsestr;

	(void)list;
	(void)envp;
	parsestr = char_to_str((*list)->next);
	ft_putstr_fd("\n", *(gettty()));
	term_reset();
	ft_parse(parsestr);
	if (parsestr && parsestr[0] != '\0')
		ft_putstr_fd("\n", *(gettty()));
	term_initiate();
	free(parsestr);
	add_history(*list);
	*list = NULL;
	char_add(list, char_new('-'));
	ft_putstr_fd("$> ", *(gettty()));
	*(getcurpos()) = 3;
	*(getactivechar()) = NULL;
	*(getactivehistory()) = NULL;
	return (1);
}
