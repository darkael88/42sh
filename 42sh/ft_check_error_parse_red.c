/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_parse_red.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:19:57 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 21:48:03 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				ft_check_error_parse_red(t_point *list)
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
				if (pipe->list && (pipe->list->out || pipe->list->app)
					&& pipe->next)
					return (ft_error_parse(6, -1));
				pipe = pipe->next;
			}
			op = op->next;
		}
		point = point->next;
	}
	return (0);
}
