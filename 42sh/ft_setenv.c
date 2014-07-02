/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:19:49 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 19:30:23 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static int		check_arg_setenv(char *str)
{
	int			status;
	int			i;

	status = 0;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (status == 0 && str[i] == '\\')
			i++;
		else if (status == 0 && str[i] == '=')
		{
			ft_putendl_fd("setenv: Syntax Error.", 2);
			return (-1);
		}
		else if (status == 0 && str[i] == '\'')
			status = 1;
		else if (status == 0 && str[i] == '"')
			status = 2;
		else if ((status == 1 && str[i] == '\'')
					|| (status == 2 && str[i] == '"'))
			status = 0;
		if (str[i])
			i++;
	}
	return (0);
}

static void		st_change_oldpwd(char *s1)
{
	t_senv		*senv;

	senv = ft_saved_env();
	ft_memdel((void **)&senv->oldpwd);
	senv->oldpwd = ft_strdup(s1);
}

static void		st_change_home(char *s1)
{
	t_senv		*senv;

	senv = ft_saved_env();
	ft_memdel((void **)&senv->home);
	senv->home = ft_strdup(s1);
}

static int		st_modif_env(char **args)
{
	char		*s1;
	char		*s2;

	if (check_arg_setenv(args[1]) == -1)
		return (1);
	if (check_arg_setenv(args[2]) == -1)
		return (1);
	s1 = ft_parse_arg_env(args[1]);
	s2 = ft_parse_arg_env(args[2]);
	set_env_value(s1, s2);
	if (ft_strcmp(s1, "OLDPWD") == 0)
		st_change_oldpwd(s2);
	if (ft_strcmp(s1, "HOME") == 0)
		st_change_home(s2);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (1);
}

int				ft_set_env(char **args)
{
	int			len;

	len = ft_tablen((void **)args);
	if (len == 1)
		ft_display_env();
	else if (len > 3)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else
		return (st_modif_env(args));
	return (1);
}
