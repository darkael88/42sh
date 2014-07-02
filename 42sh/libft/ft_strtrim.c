/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:27:52 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 17:54:34 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	start;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	size = (ft_strlen(s));
	start = 0;
	j = 1;
	while (s[start] == '\t' || s[start] == ' ' || s[start] == '\n')
		start++;
	while ((size - j) >= start && (s[size - j] == '\t' || s[size - j] == '\n'
									|| s[size - j] == ' '))
		j++;
	str = ft_strsub(s, start, size - j - start + 1);
	if (!str)
		return (NULL);
	else
		return (str);
}
