/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:31:02 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 15:46:32 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <sys/stat.h>
#include <unistd.h>
#include "struct.h"

static int		st_error_acces(char **pwd)
{
	ft_error_cd("cd", 1, *pwd);
	ft_memdel((void **)pwd);
	return (1);
}

static int		st_error_lstat(char **pwd)
{
	ft_error_cd("cd", 3, *pwd);
	ft_memdel((void **)pwd);
	return (1);
}

int				ft_cd_error_chdir(char **tmp, char **pwd)
{
	ft_error_cd("cd", 2, *pwd);
	ft_memdel((void **)tmp);
	ft_memdel((void **)pwd);
	return (1);
}

static int		st_clean_env(char **pwd, int option)
{
	if (*pwd == NULL || *pwd[0] == '\0')
	{
		set_env_value("PWD", get_env_value("HOME"));
		chdir(get_env_value("HOME"));
		if (option == 2)
			set_env_value("PWD", getcwd(NULL, 1024));
		ft_memdel((void **)pwd);
		return (0);
	}
	if (option == 1)
		set_env_value("PWD", *pwd);
	else
	{
		ft_memdel((void **)pwd);
		*pwd = getcwd(NULL, 1024);
		set_env_value("PWD", *pwd);
	}
	ft_memdel((void **)pwd);
	return (0);
}

int				ft_other_cd(char *path, int option)
{
	char		*pwd;
	char		*tmp;
	t_senv		*senv;
	struct stat	filestat;

	filestat.st_mode = S_IFDIR;
	pwd = ft_strdup(path);
	if (!pwd)
		ft_error_malloc();
	if (access(pwd, F_OK) == -1 && pwd != NULL && pwd[0] != '\0')
		return (st_error_acces(&pwd));
	if (lstat(pwd, &filestat) == -1 && pwd != NULL && pwd[0] != '\0')
		return (st_error_lstat(&pwd));
	tmp = getcwd(NULL, 1024);
	if (chdir(pwd) == -1 && pwd != NULL && pwd[0] != '\0')
		return (ft_cd_error_chdir(&tmp, &pwd));
	senv = ft_saved_env();
	ft_memdel((void **)&senv->oldpwd);
	senv->oldpwd = ft_strdup(tmp);
	ft_memdel((void **)&tmp);
	if ((get_env_value("OLDPWD")) != NULL)
		set_env_value("OLDPWD", senv->oldpwd);
	return (st_clean_env(&pwd, option));
}
