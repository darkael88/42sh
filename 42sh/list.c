/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 17:24:17 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 21:56:03 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "struct.h"

t_char		*char_new(char c)
{
	t_char	*temp;

	if (!(temp = (t_char *)malloc(sizeof(t_char))))
		ft_error_malloc();
	temp->c = c;
	temp->prev = NULL;
	temp->next = NULL;
	return (temp);
}

static void	char_add_active(t_char **first, t_char *item, t_char *temp)
{
	t_char	*active;

	active = *(getactivechar());
	if (temp == active)
	{
		item->next = temp;
		temp->prev = item;
		*first = item;
	}
	else
	{
		item->next = temp->next;
		item->prev = temp;
		if (item->next)
			item->next->prev = item;
		temp->next = item;
	}
}

void		char_add(t_char **first, t_char *item)
{
	t_char	*temp;
	t_char	*active;

	active = *(getactivechar());
	if (first == NULL || item == NULL)
		return ;
	if (*first == NULL)
		*first = item;
	else
	{
		temp = *first;
		while (temp->next && temp->next != active && temp != active)
			temp = temp->next;
		char_add_active(first, item, temp);
	}
}

t_char		*char_delete(t_char **first, t_char *item)
{
	t_char	*next;

	if (!item)
		return (NULL);
	if (item == *first)
		*first = item->next;
	else
		item->prev->next = item->next;
	if (item->next)
		item->next->prev = item->prev;
	next = item->next;
	if (item)
		free(item);
	return (next);
}

char		*char_to_str(t_char *list)
{
	char	*str;
	t_char	*temp;
	int		i;

	temp = list;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		ft_error_malloc();
	temp = list;
	i = 0;
	while (temp)
	{
		str[i] = temp->c;
		i++;
		temp = temp->next;
	}
	str[i] = '\0';
	return (str);
}
