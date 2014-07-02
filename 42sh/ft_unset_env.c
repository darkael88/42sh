/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 07:59:18 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:24:27 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "struct.h"

static int	st_search_equal(char *arg)
{
	int		i;

	i = 0;
	while (arg && arg[i] != '\0' && arg[i] != '=')
		i++;
	return (i);
}

int			ft_unset_env(char **args)
{
	t_env	*temp;
	t_env	**env;
	int		i;
	int		size;

	env = ft_getenv();
	i = 1;
	while (args[i])
	{
		temp = *env;
		while (temp)
		{
			size = st_search_equal(temp->name);
			if (!ft_strncmp(temp->name, args[i], size))
				env_delete(env, temp);
			if (temp)
				temp = temp->next;
		}
		i++;
	}
	return (1);
}
