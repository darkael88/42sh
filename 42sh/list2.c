/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 23:01:55 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:27:22 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "struct.h"

t_char		*char_dup(t_char *list)
{
	t_char	*temp;

	if (!list)
		return (char_new('-'));
	temp = NULL;
	while (list)
	{
		char_add(&temp, char_new(list->c));
		list = list->next;
	}
	return (temp);
}

void		char_wipe(t_char **list)
{
	t_char	*temp;

	temp = *list;
	while (temp)
		temp = char_delete(list, temp);
}

t_char		*char_insert_after(t_char *after, t_char *item)
{
	if (!after || !item)
		return (after);
	item->next = after->next;
	after->next = item;
	item->prev = after;
	if (item->next)
		item->next->prev = item;
	return (item);
}
