/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 20:30:26 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 21:58:26 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static int		st_check_error_status(int status)
{
	if (status == 1 || status == 2)
		return (ft_error_parse(4, -1));
	else if (status == 3)
		return (ft_error_parse(3, -1));
	else
		return (0);
}

static int		st_is_separate(t_list_p *tmp)
{
	if (tmp->next == NULL || tmp->next->str[0] == '|'
		|| tmp->next->str[0] == ';' || ft_strcmp(tmp->next->str, "&&") == 0
		|| tmp->next->str[0] == '<' || tmp->next->str[0] == '>')
		return (-1);
	else
		return (0);
}

static int		st_check_first_str(t_list_p *tmp)
{
	if (tmp->str[0] == '|' || ft_strcmp(tmp->str, "&&") == 0)
		return (ft_error_parse(3, -1));
	else if (tmp->str[0] == '>' && st_is_separate(tmp) == -1)
		return (ft_error_parse(4, -1));
	else if (tmp->str[0] == '>')
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->str, "|") == 0)
				return (ft_error_parse(6, -1));
			tmp = tmp->next;
		}
		return (ft_error_parse(3, -1));
	}
	else if (tmp->str[0] == '<' && st_is_separate(tmp) == -1)
		return (ft_error_parse(4, -1));
	else if (tmp->str[0] == '<')
		return (ft_error_parse(3, -1));
	return (0);
}

static void		st_next_tmp(int *status, t_list_p **tmp)
{
	*status = 0;
	*tmp = (*tmp)->next;
}

int				ft_check_error_parse(t_list_p *list, int status,
										int left, int right)
{
	t_list_p	*tmp;

	tmp = list;
	if (st_check_first_str(tmp) == -1)
		return (-1);
	while (tmp)
	{
		if (status == 0)
		{
			if (ft_status_zero(&tmp, &status, &left, &right) == -1)
				return (-1);
		}
		else if (status == 3 && (tmp->str[0] == '|' || tmp->str[0] == ';'
									|| ft_strcmp(tmp->str, "&&") == 0))
			return (ft_error_parse(3, -1));
		else if ((tmp->str[0] == '|' || tmp->str[0] == ';' || tmp->str[0] == '>'
					|| tmp->str[0] == '<' || ft_strcmp(tmp->str, "&&") == 0)
					&& status != 0)
			return (ft_error_parse(4, -1));
		else
			st_next_tmp(&status, &tmp);
	}
	return (st_check_error_status(status));
}
