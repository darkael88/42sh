/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 18:18:17 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/05 15:40:14 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_memtab(char ***tab, char const *s, int y, int i)
{
	int			start;

	start = -1;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
			start = i;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			i++;
		if (start >= 0)
		{
			(*tab)[y] = ft_strsub(s, start, i - start);
			start = -1;
			y++;
		}
		if (s[i] != '\0')
			i++;
	}
	(*tab)[y] = NULL;
}

static char		**ft_tab_one(char ***tab, char const *s)
{
	size_t		size;

	size = ft_strlen(s);
	*tab = (char **)malloc(sizeof(char *) * 2);
	if (size == 0)
	{
		(*tab)[0] = (char *)malloc(sizeof(char) * 1);
		(*tab)[0][0] = '\0';
	}
	else
		(*tab)[0] = ft_strdup(s);
	(*tab)[1] = NULL;
	return (*tab);
}

char			**ft_splitspace(char const *s)
{
	size_t		i;
	size_t		count;
	char		**tab;

	tab = NULL;
	if (!s)
		return (ft_tab_one(&tab, NULL));
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			count++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			i++;
	}
	if (count == 0)
		return (ft_tab_one(&tab, NULL));
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ft_memtab(&tab, s, 0, 0);
	return (tab);
}
