/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 06:18:03 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:13:20 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static t_list_p	*st_create_tlist(char *str)
{
	t_list_p	*elem;

	if (!(elem = (t_list_p *)malloc(sizeof(t_list_p))))
		ft_error_malloc();
	elem->str = str;
	elem->out = NULL;
	elem->app = NULL;
	elem->in = NULL;
	elem->next = NULL;
	return (elem);
}

void			ft_push_tlist(const char *str, t_list_p **begin,
								int *start, int *end)
{
	t_list_p	*elem;
	t_list_p	*tmp;
	char		*arg;

	if (*start != -1 && *end != -1)
	{
		if (!(arg = ft_strsub(str, *start, *end - *start)))
			ft_error_malloc();
		elem = st_create_tlist(arg);
		if (*begin)
		{
			tmp = *begin;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = elem;
		}
		else
			*begin = elem;
		*start = -1;
		*end = -1;
	}
}

t_pipe			*ft_create_tpipe(t_list_p *ref)
{
	t_pipe		*elem;

	if (!(elem = (t_pipe *)malloc(sizeof(t_pipe))))
		ft_error_malloc();
	elem->list = ref;
	elem->next = NULL;
	return (elem);
}

t_op			*ft_create_t_op(t_list_p *ref)
{
	t_op		*elem;

	if (!(elem = (t_op *)malloc(sizeof(t_op))))
		ft_error_malloc();
	elem->pipe = ft_create_tpipe(ref);
	elem->next = NULL;
	elem->type = 0;
	return (elem);
}

t_point			*ft_create_tpoint(t_list_p *ref)
{
	t_point		*elem;

	if (!(elem = (t_point *)malloc(sizeof(t_point))))
		ft_error_malloc();
	elem->op = ft_create_t_op(ref);
	elem->next = NULL;
	return (elem);
}
