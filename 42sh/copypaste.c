/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copypaste.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 22:19:52 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:05:05 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

t_copy		*getcp(void)
{
	static t_copy	copypaste = {NULL, NULL, NULL};

	return (&copypaste);
}

void		cp_copy(void)
{
	t_copy	*cp;
	t_char	*temp;

	cp = getcp();
	cp->data = NULL;
	temp = cp->left;
	while (temp && temp != cp->right)
	{
		char_add(&(cp->data), char_new(temp->c));
		temp = temp->next;
	}
}

void		cp_paste(t_char **list)
{
	t_copy		*cp;
	t_char		*templist;
	t_char		*tempdata;
	t_char		*activechar;

	cp = getcp();
	activechar = *(getactivechar());
	if (cp->data)
	{
		templist = *list;
		tempdata = cp->data;
		while (templist && templist->next && templist->next != activechar)
			templist = templist->next;
		while (tempdata)
		{
			templist = char_insert_after(templist, char_new(tempdata->c));
			tempdata = tempdata->next;
		}
	}
}

void		cp_refresh(t_char *tchar)
{
	t_copy		*cp;

	cp = getcp();
	if (!cp->left && !cp->right)
	{
		cp->left = tchar;
		cp->right = tchar;
	}
	else if (tchar == cp->left || tchar == cp->right)
		(void)tchar;
	else if (cp->left && tchar == cp->left->prev)
		cp->left = tchar;
	else if (cp->right && tchar == cp->right->next)
		cp->right = tchar;
	else if (cp->left && tchar == cp->left->next)
		cp->left = tchar;
	else if (cp->right && tchar == cp->right->prev)
		cp->right = tchar;
	else
	{
		cp->left = tchar;
		cp->right = tchar;
	}
}

int			cp_reset(int mode)
{
	t_copy		*cp;
	t_char		*temp;
	t_char		*previous;

	cp = getcp();
	if (mode == 0 && (!cp || (!cp->left && !cp->right)))
		return (0);
	if (mode == 1 && (!cp || (!cp->left && !cp->right && !cp->data)))
		return (0);
	cp->right = NULL;
	cp->left = NULL;
	if (mode == 1)
	{
		temp = cp->data;
		while (temp)
		{
			previous = temp;
			temp = temp->next;
			if (previous)
				free(previous);
		}
		cp->data = NULL;
	}
	return (1);
}
