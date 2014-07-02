/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 07:16:01 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 07:16:08 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static int	ft_tab_total_len(char **tab)
{
	int		len;
	int		j;
	int		i;

	len = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
			i++;
		len += i + 1;
		j++;
	}
	return (len);
}

char		*ft_tab_implode(char **tab, char c)
{
	int		len;
	int		j;
	int		i;
	char	*temp;

	len = ft_tab_total_len(tab);
	temp = (char *)malloc((len + 1) * sizeof(char));
	len = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			temp[len] = tab[j][i];
			i++;
			len++;
		}
		if (tab[j + 1])
			temp[len] = c;
		if (tab[j + 1])
			len++;
		j++;
	}
	return (temp);
}

int			ft_is_env_i(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i] || str[i] != 'e')
		return (0);
	i++;
	if (!str[i] || str[i] != 'n')
		return (0);
	i++;
	if (!str[i] || str[i] != 'v')
		return (0);
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i] || str[i] != '-')
		return (0);
	i++;
	if (!str[i] || str[i] != 'i')
		return (0);
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int			ft_is_env(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i] || str[i] != 'e')
		return (0);
	i++;
	if (!str[i] || str[i] != 'n')
		return (0);
	i++;
	if (!str[i] || str[i] != 'v')
		return (0);
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
