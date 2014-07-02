/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:39:01 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:14:42 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

char	**get_env_pathlist(char **envp, int argc, char **argv)
{
	int		j;
	char	**temp;

	if (argc || argv)
	{
	}
	if (!envp)
		ft_errorexit("Error : no env\n");
	j = 0;
	while (envp[j] && ft_strstr(envp[j], "PATH=") != envp[j])
		j++;
	if (!envp[j])
	{
		if (!(temp = (char **)malloc(2 * sizeof(char *))))
			ft_error_malloc();
		temp[0] = ft_strdup("1");
		temp[1] = NULL;
		return (temp);
	}
	return (ft_strsplit((envp[j] + 5), ':'));
}

t_env	*ft_load_env(char **envp)
{
	int		j;
	t_env	*temp;
	t_env	*new;
	char	**splitenv;

	temp = NULL;
	j = 0;
	while (envp[j])
	{
		splitenv = split_env(envp[j]);
		new = env_new(splitenv[0], splitenv[1]);
		env_add(&temp, new);
		ft_delfulltab((void ***)&splitenv);
		j++;
	}
	return (temp);
}

int		ft_display_env(void)
{
	t_env	*env;

	env = *(ft_getenv());
	while (env)
	{
		ft_putstr(env->name);
		ft_putstr("=");
		ft_putstr(env->value);
		ft_putstr("\n");
		env = env->next;
	}
	return (1);
}
