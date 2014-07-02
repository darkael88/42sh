/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_tpoint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 10:00:16 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:20:42 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static void		st_del_point(t_point **list, t_list_p **cur, t_list_p **prev)
{
	if (*cur && ft_strcmp((*cur)->str, ";") == 0)
	{
		if (*prev)
			(*prev)->next = NULL;
		(*prev) = *cur;
		(*cur) = (*cur)->next;
		ft_memdel((void **)&(*prev)->str);
		free(*prev);
		while (*cur && ft_strcmp((*cur)->str, ";") == 0)
		{
			(*prev) = *cur;
			(*cur) = (*cur)->next;
			ft_memdel((void **)&(*prev)->str);
			free(*prev);
		}
		if (*cur)
			(*list) = ft_create_tpoint((*cur));
	}
}

static void		st_first_point(t_point *point, t_list_p **current)
{
	t_list_p	*prev;

	prev = point->op->pipe->list;
	point->op->pipe->list = point->op->pipe->list->next;
	ft_memdel((void **)&prev->str);
	free(prev);
	prev = NULL;
	*current = point->op->pipe->list;
}

static void		st_check_point(t_point **point, t_list_p **cur, t_list_p **prev)
{
	st_del_point(&(*point)->next, cur, prev);
	if ((*point)->next)
		*point = (*point)->next;
	if (*cur)
	{
		*prev = *cur;
		*cur = (*cur)->next;
	}
}

void			ft_separate_tpoint(t_point *list)
{
	t_point		*point;
	t_list_p	*prev;
	t_list_p	*current;

	point = list;
	prev = NULL;
	current = point->op->pipe->list;
	while (current && ft_strcmp(current->str, ";") == 0)
		st_first_point(point, &current);
	while (current)
		st_check_point(&point, &current, &prev);
	point = list;
	while (point)
	{
		ft_separate_op(point->op);
		point = point->next;
	}
}
