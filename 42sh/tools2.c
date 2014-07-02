/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 23:12:29 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:29:30 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

char	**get_pathlist(void)
{
	char	**tab;

	tab = ft_strsplit(get_env_value("PATH"), ':');
	if (tab)
		return (tab);
	tab = (char **)malloc(sizeof(char *));
	tab[0] = NULL;
	return (tab);
}

t_env	**ft_getenv(void)
{
	static t_env	**env = NULL;

	if (env == NULL)
		env = (t_env **)malloc(sizeof(t_env *));
	return (env);
}
