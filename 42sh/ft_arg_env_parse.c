/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_env_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 08:45:54 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 19:18:27 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>

static int		st_check_char(char *src, int *i, int *status)
{
	if (*status == 0 && src[*i] == '\\')
	{
		(*i)++;
		return (0);
	}
	else if ((*status == 1 && src[*i] == '\'')
				|| (*status == 2 && src[*i] == '"'))
		*status = 0;
	else if (*status == 0 && src[*i] == '\'')
		*status = 1;
	else if (*status == 0 && src[*i] == '"')
		*status = 2;
	else
		return (0);
	return (1);
}

static void		st_fill_str(char *str, char *src, int *i, int *j)
{
	str[*j] = src[*i];
	(*j)++;
}

char			*ft_parse_arg_env(char *src)
{
	char		*str;
	int			i;
	int			j;
	int			status;

	str = NULL;
	if (src)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
			ft_error_malloc();
		i = 0;
		j = 0;
		status = 0;
		while (src[i] != '\0')
		{
			if (st_check_char(src, &i, &status) == 0)
				st_fill_str(str, src, &i, &j);
			if (src[i])
				i++;
		}
		str[j] = '\0';
	}
	return (str);
}
