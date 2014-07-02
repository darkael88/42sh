/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:53:20 by mdarty            #+#    #+#             */
/*   Updated: 2013/11/24 15:07:08 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (s2[0] == '\0' || n == 0)
		return (s1);
	size = ft_strlen(s1);
	while ((char)s2[i] != '\0' && n > 0)
	{
		s1[size] = s2[i];
		i++;
		size++;
		n--;
	}
	s1[size] = '\0';
	return (s1);
}
