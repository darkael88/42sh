/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 20:40:04 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:37:42 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

t_char		***getactivelist(void)
{
	static t_char	**active = NULL;

	return (&active);
}

int			check_quotes(char *str, int i)
{
	int		start;

	start = i;
	if (str[i] != '\"' && str[i] != '\'')
		return (1);
	if (str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
	}
	if (str[i] == '\"' || str[i] == '\'')
		return (i - start + 1);
	return (i - start);
}

t_char		**move_active_char_back(t_char **list)
{
	t_char	*temp;
	t_char	**active;

	active = getactivechar();
	if (*list)
	{
		temp = *active;
		if ((*list)->next != temp)
		{
			if (!temp)
			{
				temp = *list;
				while (temp->next)
					temp = temp->next;
			}
			else if (temp->prev)
				temp = temp->prev;
			if (temp != *(getactivechar()))
				cursor_move_left(1);
		}
		*active = temp;
	}
	return (active);
}

char		**split_env(char *str)
{
	int		i;
	char	**temp;

	temp = (char **)malloc(3 * sizeof(char *));
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	temp[0] = ft_strsub(str, 0, i);
	temp[1] = ft_strsub(str, i + 1, ft_strlen(str) - i);
	temp[2] = NULL;
	return (temp);
}

char		**env_to_tab(void)
{
	char	**tab;
	t_env	**env;
	t_env	*temp;
	int		i;

	env = ft_getenv();
	i = 0;
	temp = *env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	tab = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	temp = *env;
	while (temp)
	{
		tab[i] = ft_strglue(temp->name, "=", temp->value);
		i++;
		temp = temp->next;
	}
	tab[i] = NULL;
	return (tab);
}
