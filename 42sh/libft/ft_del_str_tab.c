/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 16:38:46 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 17:21:56 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_del_str_tab(char ***tab, size_t line, size_t len)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	if (*tab && line < len)
	{
		if ((tmp = (char **)malloc(sizeof(char *) * (len))))
		{
			i = 0;
			j = 0;
			while (i < (len - 1))
			{
				if (j != line)
				{
					tmp[i] = ft_strdup((*tab)[j]);
					i++;
				}
				j++;
			}
			tmp[len - 1] = NULL;
			ft_delfulltab((void ***)tab);
		}
		return (tmp);
	}
	return (*tab);
}
