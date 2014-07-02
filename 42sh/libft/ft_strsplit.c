/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:28:37 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/05 15:40:32 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_memtab(char **tab, char const *s, char c, int i)
{
	int			start;
	int			y;

	start = -1;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (start >= 0)
		{
			tab[y] = ft_strsub(s, start, i - start);
			start = -1;
			y++;
		}
		if (s[i] != '\0')
			i++;
	}
	tab[y] = NULL;
}

static char		**ft_tab_one(char **tab, char const *s)
{
	size_t		size;

	size = ft_strlen(s);
	tab = (char **)malloc(sizeof(char *) * 2);
	if (size == 0)
	{
		tab[0] = (char *)malloc(sizeof(char) * 1);
		tab[0][0] = '\0';
	}
	else
		tab[0] = ft_strdup(s);
	tab[1] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			count;
	char		**tab;

	tab = NULL;
	if (!s)
		return (ft_tab_one(tab, NULL));
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			i++;
	}
	if (count == 0)
		return (ft_tab_one(NULL, NULL));
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ft_memtab(tab, s, c, 0);
	return (tab);
}
