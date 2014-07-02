/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:29:23 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 08:02:31 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*zone;

	if (!(zone = (char *)malloc(size * sizeof(*zone))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		zone[i] = 0;
		i++;
	}
	return (zone);
}
