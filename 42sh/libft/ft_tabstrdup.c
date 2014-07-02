/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 07:15:54 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/04 07:51:42 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_tabstrdup(char **src)
{
	size_t		size;
	size_t		i;
	char		**tab;

	tab = NULL;
	if (src)
	{
		size = ft_tablen((void **)src);
		if ((tab = (char **)malloc(sizeof(char *) * (size + 1))))
		{
			i = 0;
			while (i < size)
			{
				tab[i] = ft_strdup(src[i]);
				i++;
			}
			tab[i] = NULL;
		}
	}
	return (tab);
}
