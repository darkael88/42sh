/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:02:48 by mdarty            #+#    #+#             */
/*   Updated: 2013/12/01 20:26:16 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	count = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size < i)
		return (size + j);
	while (src[count] != '\0' && count + i < size - 1)
	{
		dst[i + count] = src[count];
		count++;
	}
	dst[i + count] = '\0';
	return (i + j);
}
