/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_parse_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 00:53:49 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 22:12:06 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

void			ft_send_parse_cmd(t_point *list)
{
	t_point		*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->op && tmp->op->pipe && tmp->op->pipe->list
			&& tmp->op->pipe->list->str && tmp->op->pipe->list->str[0] != '\0')
			ft_apply_cmds(tmp->op);
		tmp = tmp->next;
	}
}
