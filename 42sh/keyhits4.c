/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhits4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:56:48 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:13:14 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "struct.h"

int		key_alt_c(t_char **list, char **envp)
{
	t_copy	*cp;
	t_char	*temp;

	(void)list;
	(void)envp;
	cp = getcp();
	if (!cp || !cp->left)
		return (1);
	temp = cp->left;
	cp->data = NULL;
	while (temp && temp != cp->right)
	{
		char_add(&(cp->data), char_new(temp->c));
		temp = temp->next;
	}
	return (1);
}

int		key_alt_v(t_char **list, char **envp)
{
	(void)envp;
	cp_paste(list);
	refresh_command_line(list);
	return (1);
}

int		key_do_nothing(t_char **list, char **envp)
{
	(void)list;
	(void)envp;
	return (1);
}
