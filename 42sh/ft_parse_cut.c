/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 06:42:15 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 19:33:13 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static int	st_check_str_parse(const char *str, int *i, int *status, int *end)
{
	if ((*status == 1 && str[*i] == '\'') || (*status == 2 && str[*i] == '"'))
		*status = 0;
	else if (*status == 0)
	{
		if (str[*i] == '\'')
			*status = 1;
		else if (str[*i] == '"')
			*status = 2;
		else if (str[*i] == '\\')
		{
			(*i)++;
			if (str[*i] == '\0')
				return (-2);
			else if (str[*i] == '\\' || str[*i] == '\'' || str[*i] == '"')
				(*i)++;
		}
		else if (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ';'
					|| str[*i] == '|' || str[*i] == '&' || str[*i] == '<'
					|| str[*i] == '>' || str[*i] == '\0')
		{
			*end = *i;
			return (1);
		}
	}
	return (0);
}

static int	st_check_separate(const char *str, int *i, int *start, int *end)
{
	if (str[*i] == ';' || str[*i] == '|' || str[*i] == '&' || str[*i] == '<'
		|| str[*i] == '>')
	{
		*start = *i;
		*end = *i + 1;
		if ((str[*i] == '<' && str[*i + 1] == '<')
			|| (str[*i] == '>' && str[*i + 1] == '>')
			|| (str[*i] == '|' && str[*i + 1] == '|')
			|| (str[*i] == '&' && str[*i + 1] == '&'))
		{
			(*i)++;
			(*end) = *i + 1;
		}
		(*i)++;
		if (str[*i] == '<' || str[*i] == '|' || str[*i] == ';'
			|| str[*i] == '>' || str[*i] == '&')
			return (1);
	}
	return (0);
}

static int	st_parse_cut(const char *s, t_list_p **begin, int *i, int *status)
{
	int		ret;
	int		start;
	int		end;

	ret = 0;
	start = -1;
	end = -1;
	while (s[*i] != '\0' && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	start = *i;
	while (s[*i] != '\0'
			&& (ret = st_check_str_parse(s, i, status, &end)) == 0)
		(*i)++;
	if (ret < 0)
		return (ret);
	end = *i;
	if (end != start)
		ft_push_tlist(s, begin, &start, &end);
	while (s[*i] != '\0' && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
	while (st_check_separate(s, i, &start, &end) == 1)
		ft_push_tlist(s, begin, &start, &end);
	ft_push_tlist(s, begin, &start, &end);
	return (0);
}

int			ft_parse_str(const char *str, t_list_p **begin, int i, int status)
{
	int		ret;

	ret = 0;
	while (str[i] != '\0')
	{
		if ((ret = st_parse_cut(str, begin, &i, &status)) < 0)
			return (ret);
	}
	if (status != 0)
		return (ft_error_parse(status, -1));
	return (0);
}
