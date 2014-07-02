/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str4join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 11:04:21 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 11:07:49 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_fill_strjoin(char *dest, char *src, size_t *i, size_t *j)
{
	if (src)
	{
		while (src[*j] != '\0')
		{
			dest[*i] = src[*j];
			*i = *i + 1;
			*j = *j + 1;
		}
	}
}

char			*ft_str4join(char const *s1, char const *s2,
								char const *s3, char const *s4)
{
	size_t		i;
	size_t		j;
	char		*str;
	size_t		size;

	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + ft_strlen(s4);
	if (!(str = ft_strnew(size)))
		return (NULL);
	i = 0;
	j = 0;
	ft_fill_strjoin(str, (char *)s1, &i, &j);
	j = 0;
	ft_fill_strjoin(str, (char *)s2, &i, &j);
	j = 0;
	ft_fill_strjoin(str, (char *)s3, &i, &j);
	j = 0;
	ft_fill_strjoin(str, (char *)s4, &i, &j);
	str[i] = '\0';
	return (str);
}
