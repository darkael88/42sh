/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 11:27:24 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 11:39:04 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_chrsplit(const char *s, int c, char **prev, char **after)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] != '\0' && s[i] == c)
	{
		*prev = ft_strsub(s, 0, i);
		if (s[i + 1] != '\0')
			*after = ft_strdup(s + i + 1);
		else
			*after = NULL;
		return ((char *)(s + i));
	}
	else
		return (NULL);
}
