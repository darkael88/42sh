/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 20:10:44 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:12:24 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

t_char		**gethistory(void)
{
	static t_char	**history = NULL;
	int				i;

	if (history == NULL)
	{
		i = 0;
		history = (t_char **)malloc((MAXHISTORY + 1) * sizeof(t_char *));
		if (history)
		{
			while (i < (MAXHISTORY + 1))
			{
				history[i] = NULL;
				i++;
			}
		}
	}
	return (history);
}

void		add_history(t_char *list)
{
	int		i;
	t_char	**history;

	history = gethistory();
	i = (MAXHISTORY - 1);
	while (i > 0)
	{
		if (i == (MAXHISTORY - 1) && history[i] != NULL)
			char_wipe(&(history[i]));
		history[i] = history[i - 1];
		i--;
	}
	history[0] = list;
}

void		display_history(void)
{
	int		i;
	t_char	**history;
	char	*tmp;

	history = gethistory();
	i = 0;
	while (i < MAXHISTORY && history[i])
	{
		ft_putnbr_fd(i + 1, *(gettty()));
		ft_putstr_fd(" : ", *(gettty()));
		if (history[i])
		{
			tmp = char_to_str(history[i] + 1);
			ft_putstr_fd(tmp, *(gettty()));
			ft_memdel((void **)&tmp);
		}
		else
			ft_putstr_fd("NULL", *(gettty()));
		ft_putstr_fd("\n", *(gettty()));
		i++;
	}
}
