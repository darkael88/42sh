/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:33:53 by mdarty            #+#    #+#             */
/*   Updated: 2013/12/01 20:23:23 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*size;

	size = (unsigned char *)malloc(sizeof(*size) * n);
	ft_memcpy(size, s2, n);
	ft_memcpy(s1, size, n);
	return (s1);
}
