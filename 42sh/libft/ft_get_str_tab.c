/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 17:41:00 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/04 06:33:23 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_fill_str(char **tmp, char *str, size_t *i, size_t line)
{
	if (*i == line)
	{
		tmp[*i] = ft_strdup(str);
		(*i)++;
	}
}

char		**ft_get_str_tab(char ***tab, char *str, size_t line, size_t len)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	if ((!(*tab)) || line > len)
		return (*tab);
	if ((tmp = (char **)malloc(sizeof(char *) * (len + 2))))
	{
		i = 0;
		j = 0;
		while ((*tab)[j])
		{
			ft_fill_str(tmp, str, &i, line);
			tmp[i] = ft_strdup((*tab)[j]);
			i++;
			j++;
		}
		ft_fill_str(tmp, str, &i, line);
		tmp[i] = NULL;
		ft_delfulltab((void ***)tab);
	}
	return (tmp);
}
