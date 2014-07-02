/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_status_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:42:29 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:47:41 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "struct.h"

static int	st_list_pipe(t_list_p **list, int *status, int *left, int *right)
{
	*status = 3;
	*right = 0;
	*left = 0;
	if ((*list)->str[0] == '|' && (*list)->next
		&& (*list)->next->str[0] == '>')
		return (ft_error_parse(3, -1));
	else if ((*list)->str[0] == '|' && (*list)->next
				&& (*list)->next->str[0] == '<')
		return (ft_error_parse(5, -1));
	return (0);
}

static void	st_list_point(int *right, int *left)
{
	*right = 0;
	*left = 0;
}

int			ft_status_zero(t_list_p **list, int *status, int *left, int *right)
{
	if ((*list)->str[0] == '<')
	{
		*status = 1;
		if (*left == 1)
			return (ft_error_parse(5, -1));
		*left = 1;
	}
	else if ((*list)->str[0] == '>')
	{
		*status = 2;
		if (*right == 1)
			return (ft_error_parse(6, -1));
		*right = 1;
	}
	else if ((*list)->str[0] == '|' || ft_strcmp((*list)->str, "&&") == 0)
	{
		if (st_list_pipe(list, status, left, right) == -1)
			return (-1);
	}
	else if (ft_strcmp((*list)->str, ";") == 0)
		st_list_point(right, left);
	*list = (*list)->next;
	return (0);
}
