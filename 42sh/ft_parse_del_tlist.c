/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_del_tlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 06:29:53 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 18:47:23 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static void		st_del_full_tlist(t_list_p **begin)
{
	t_list_p	*tmp;
	t_list_p	*tmp2;

	if (*begin)
	{
		tmp = *begin;
		tmp2 = tmp->next;
		while (tmp2)
		{
			*begin = tmp2;
			ft_memdel((void **)&tmp->str);
			ft_memdel((void **)&tmp->out);
			ft_memdel((void **)&tmp->app);
			ft_memdel((void **)&tmp->in);
			free(tmp);
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		ft_memdel((void **)&tmp->str);
		ft_memdel((void **)&tmp->out);
		ft_memdel((void **)&tmp->app);
		ft_memdel((void **)&tmp->in);
		free(*begin);
		*begin = NULL;
	}
}

static void		st_del_pipe(t_pipe **begin)
{
	t_pipe		*tmp;
	t_pipe		*tmp2;

	if (*begin)
	{
		tmp = *begin;
		tmp2 = tmp->next;
		while (tmp2)
		{
			*begin = tmp2;
			st_del_full_tlist(&tmp->list);
			free(tmp);
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		st_del_full_tlist(&(*begin)->list);
		free(*begin);
		*begin = NULL;
	}
}

static void		st_del_op(t_op **begin)
{
	t_op		*tmp;
	t_op		*tmp2;

	if (*begin)
	{
		tmp = *begin;
		tmp2 = tmp->next;
		while (tmp2)
		{
			*begin = tmp2;
			st_del_pipe(&tmp->pipe);
			free(tmp);
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		st_del_pipe(&(*begin)->pipe);
		free(*begin);
		*begin = NULL;
	}
}

void			ft_del_full_point(t_point **begin)
{
	t_point		*tmp;
	t_point		*tmp2;

	if (*begin)
	{
		tmp = *begin;
		tmp2 = tmp->next;
		while (tmp2)
		{
			*begin = tmp2;
			st_del_op(&tmp->op);
			free(tmp);
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		st_del_op(&(*begin)->op);
		free(*begin);
		*begin = NULL;
	}
}
