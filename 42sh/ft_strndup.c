/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:50:38 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:24:04 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int				length;
	unsigned int	i;
	char			*s1dup;

	length = 0;
	i = 0;
	while (s1[length] != '\0')
		length++;
	if (!(s1dup = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (i < n)
	{
		s1dup[i] = s1[i];
		i++;
	}
	s1dup[i] = '\0';
	return (s1dup);
}
