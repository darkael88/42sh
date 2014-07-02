/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 18:48:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:14:12 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static void		st_create_pipe(t_pipe **pipe, t_list_p **prev, t_list_p **cur)
{
	(*prev)->next = (*cur)->next;
	ft_memdel((void **)&(*cur)->str);
	free(*cur);
	(*cur) = (*prev)->next;
	(*prev)->next = NULL;
	(*pipe) = ft_create_tpipe(*cur);
}

void			ft_separate_pipe(t_pipe *pipe)
{
	t_pipe		*tmp;
	t_list_p	*prev;
	t_list_p	*current;

	tmp = pipe;
	prev = NULL;
	current = pipe->list;
	while (current)
	{
		if (ft_strcmp(current->str, "|") == 0)
		{
			st_create_pipe(&tmp->next, &prev, &current);
			tmp = tmp->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
