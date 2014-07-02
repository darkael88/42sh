/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:14:57 by mdarty            #+#    #+#             */
/*   Updated: 2013/12/01 20:27:17 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (ft_isascii(c) == 1)
	{
		i = ft_strlen(s);
		while (i >= 0 && s[i] != c)
			i--;
		if (s[i] == c)
			return ((char *)(s + i));
		else
			return (NULL);
	}
	return (NULL);
}
