/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:44:50 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 09:18:38 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (s)
	{
		i = 0;
		tmp = (unsigned char *)s;
		while (i < n)
		{
			if (tmp[i] == (unsigned char)c)
			{
				return (&tmp[i]);
			}
			i++;
		}
	}
	return (NULL);
}
