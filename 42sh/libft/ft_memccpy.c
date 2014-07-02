/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:27:02 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 09:22:53 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp;
	unsigned char const	*src;

	tmp = (unsigned char *)s1;
	src = (unsigned char const *)s2;
	i = 0;
	while (i < n)
	{
		tmp[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (tmp + i + 1);
		i++;
	}
	s1 = tmp;
	return (NULL);
}
