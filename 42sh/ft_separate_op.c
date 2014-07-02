/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 17:50:47 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 19:05:12 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static void		st_create_t_op(t_op **op, t_list_p **prev,
								t_list_p **cur, int type)
{
	(*prev)->next = (*cur)->next;
	ft_memdel((void **)&(*cur)->str);
	free(*cur);
	(*cur) = (*prev)->next;
	(*prev)->next = NULL;
	(*op) = ft_create_t_op(*cur);
	(*op)->type = type;
}

static void		st_next_list(t_list_p **prev, t_list_p **current)
{
	*prev = *current;
	*current = (*current)->next;
}

static void		st_send_separate(t_op *op)
{
	t_op		*tmp;

	tmp = op;
	while (tmp)
	{
		ft_separate_pipe(tmp->pipe);
		tmp = tmp->next;
	}
}

void			ft_separate_op(t_op *op)
{
	t_op		*tmp;
	t_list_p	*prev;
	t_list_p	*current;

	tmp = op;
	prev = NULL;
	current = op->pipe->list;
	while (current)
	{
		if (ft_strcmp(current->str, "&&") == 0)
		{
			st_create_t_op(&tmp->next, &prev, &current, 2);
			tmp = tmp->next;
		}
		else if (ft_strcmp(current->str, "||") == 0)
		{
			st_create_t_op(&tmp->next, &prev, &current, 1);
			tmp = tmp->next;
		}
		else
			st_next_list(&prev, &current);
	}
	st_send_separate(op);
}
