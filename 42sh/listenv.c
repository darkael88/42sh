/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:37:13 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:13:40 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

t_env	*env_new(char *name, char *value)
{
	t_env	*temp;

	if (!(temp = (t_env *)malloc(sizeof(t_env))))
		ft_error_malloc();
	temp->name = ft_strdup(name);
	temp->value = ft_strdup(value);
	temp->next = NULL;
	return (temp);
}

void	env_add(t_env **list, t_env *item)
{
	t_env	*temp;

	if (!list || !item)
		return ;
	if (*list == NULL)
		*list = item;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = item;
	}
}

void	env_delete(t_env **list, t_env *item)
{
	t_env	*temp;

	if (*list && item && *list == item)
	{
		temp = *list;
		*list = temp->next;
		ft_memdel((void **)&temp->name);
		ft_memdel((void **)&temp->value);
		ft_memdel((void **)&temp);
	}
	else
	{
		temp = *list;
		while (temp && temp->next && temp->next != item)
			temp = temp->next;
		if (temp && temp->next && temp->next == item)
			temp->next = item->next;
		else
			temp->next = NULL;
		ft_memdel((void **)&item->name);
		ft_memdel((void **)&item->value);
		ft_memdel((void **)&item);
	}
}

char	*get_env_value(char *name)
{
	t_env	*env;

	env = *(ft_getenv());
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int		set_env_value(char *name, char *value)
{
	t_env	**env;
	t_env	*temp;

	env = ft_getenv();
	temp = *env;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
		{
			if (temp->value)
				free(temp->value);
			temp->value = ft_strdup(value);
			return (1);
		}
		temp = temp->next;
	}
	temp = env_new(name, value);
	env_add(env, temp);
	return (1);
}
