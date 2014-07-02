/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:49:51 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 21:51:20 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>
#include "struct.h"

static char		*st_red(t_list_p **tmp, t_list_p **current)
{
	char		*str;

	(*current)->next = (*tmp)->next->next;
	str = ft_strdup((*tmp)->next->str);
	ft_memdel((void **)&(*tmp)->next->str);
	free((*tmp)->next);
	ft_memdel((void **)&(*tmp)->str);
	free(*tmp);
	*tmp = (*current)->next;
	return (str);
}

static void		st_concatene(t_list_p **list)
{
	t_list_p	*current;
	t_list_p	*tmp;
	char		*str;

	current = *list;
	tmp = current->next;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, "<") == 0)
			current->in = st_red(&tmp, &current);
		else if (ft_strcmp(tmp->str, ">") == 0)
			current->out = st_red(&tmp, &current);
		else if (ft_strcmp(tmp->str, ">>") == 0)
			current->app = st_red(&tmp, &current);
		else
		{
			current->next = tmp->next;
			str = ft_str3join(current->str, " ", tmp->str);
			ft_memdel((void **)&current->str);
			ft_memdel((void **)&tmp->str);
			free(tmp);
			current->str = str;
			tmp = current->next;
		}
	}
}

int				ft_parse_red(t_point *list)
{
	t_point		*point;
	t_op		*op;
	t_pipe		*pipe;

	point = list;
	if (!point || !point->op || !point->op->pipe || !point->op->pipe->list)
		return (-1);
	while (point)
	{
		op = point->op;
		while (op)
		{
			pipe = op->pipe;
			while (pipe)
			{
				if (pipe->list)
					st_concatene(&pipe->list);
				pipe = pipe->next;
			}
			op = op->next;
		}
		point = point->next;
	}
	return (0);
}
