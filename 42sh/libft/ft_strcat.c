/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:47:39 by mdarty            #+#    #+#             */
/*   Updated: 2013/11/24 15:02:44 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (s2[0] == '\0')
		return (s1);
	size = ft_strlen(s1);
	while ((char)s2[i] != '\0')
	{
		s1[size] = s2[i];
		i++;
		size++;
	}
	s1[size] = '\0';
	return (s1);
}
