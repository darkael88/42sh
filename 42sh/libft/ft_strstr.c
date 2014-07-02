/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:19:34 by mdarty            #+#    #+#             */
/*   Updated: 2013/12/01 14:34:39 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	is1;
	unsigned int	is2;
	unsigned int	count;

	is1 = 0;
	is2 = 0;
	if (*s2 == 0 || s2 == NULL)
		return ((char *)s1);
	while (s1[is1] != '\0')
	{
		count = is1;
		while (s1[is1] == s2[is2] && s1[is1] != '\0')
		{
			if (s2[is2 + 1] == '\0')
				return ((char *)(s1 + count));
			is1++;
			is2++;
		}
		is2 = 0;
		is1++;
	}
	return (NULL);
}
