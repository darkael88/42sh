/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:29:10 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 16:23:15 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static void				st_reinit_status(int *status, int *i)
{
	*status = 0;
	(*i)++;
}

static void				st_fill_str(char *src, char *str, int *i, int *j)
{
	str[*j] = src[*i];
	(*j)++;
}

static char				*st_check_char(char *src, int *i, int j, int status)
{
	char		*str;

	str = strdup(&src[*i]);
	while (src[*i] != '\0' && (str[*i] == '\t' || str[*i] == ' '))
		(*i)++;
	while (src[*i] != '\0')
	{
		if (status == 0 && src[*i] == '\'')
			status = 1;
		else if (status == 0 && src[*i] == '"')
			status = 2;
		else if (status == 0 && src[*i] == '\\')
			(*i)++;
		else if (status == 0 && src[*i] == ' ')
			break ;
		else if ((status == 1 && src[*i] == '\'')
					|| (status == 2 && src[*i] == '"'))
			st_reinit_status(&status, i);
		else
			st_fill_str(src, str, i, &j);
		if (src[*i])
			(*i)++;
	}
	str[j] = '\0';
	return (str);
}

char					**ft_strsplit_cmd(char *src)
{
	char		**tab;
	int			i;
	int			y;

	tab = NULL;
	if (src && src[0])
	{
		if (!(tab = (char **)malloc(sizeof(char *) * (ft_strlen(src) + 2))))
			return (NULL);
		i = 0;
		y = 0;
		while (src[i] != '\0')
		{
			tab[y] = st_check_char(src, &i, 0, 0);
			if (src[i] != '\0')
				i++;
			y++;
		}
		tab[y] = NULL;
	}
	return (tab);
}
