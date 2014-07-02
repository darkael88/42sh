/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 06:38:18 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 21:49:42 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static t_point	*st_init_struct(void)
{
	t_point		*elem;

	if (!(elem = (t_point *)malloc(sizeof(t_point))))
		ft_error_malloc();
	elem->next = NULL;
	if (!(elem->op = (t_op *)malloc(sizeof(t_op))))
		ft_error_malloc();
	elem->op->next = NULL;
	elem->op->type = 0;
	if (!(elem->op->pipe = (t_pipe *)malloc(sizeof(t_pipe))))
		ft_error_malloc();
	elem->op->pipe->next = NULL;
	elem->op->pipe->list = NULL;
	return (elem);
}

static int		st_after_check(t_point **list)
{
	int			ret;

	ft_separate_tpoint(*list);
	if ((ft_parse_red(*list) < 0))
	{
		ft_del_full_point(list);
		return (-1);
	}
	if ((ret = ft_check_error_parse_red(*list)) < 0)
	{
		ft_del_full_point(list);
		return (ret);
	}
	ft_send_parse_cmd(*list);
	ft_del_full_point(list);
	return (0);
}

int				ft_parse(const char *str)
{
	t_point		*list;
	int			ret;

	if (!str || str[0] == '\0')
		return (0);
	list = st_init_struct();
	if ((ret = ft_parse_str(str, &list->op->pipe->list, 0, 0)) < 0)
	{
		ft_del_full_point(&list);
		return (ret);
	}
	if ((ret = ft_check_error_parse(list->op->pipe->list, 0, 0, 0)) < 0)
	{
		ft_del_full_point(&list);
		return (ret);
	}
	return (st_after_check(&list));
}
