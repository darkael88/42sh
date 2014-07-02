/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 13:34:03 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 15:44:30 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int				ft_cd_home(void)
{
	struct stat		filestat;
	t_senv			*senv;
	char			*cwd;

	filestat.st_mode = S_IFDIR;
	senv = ft_saved_env();
	if (senv->home == NULL)
		return (ft_error_cd("cd", 5, NULL));
	if (access(senv->home, F_OK) == -1)
		return (ft_error_cd("cd", 6, NULL));
	if (lstat(senv->home, &filestat) == -1)
		return (ft_error_cd("cd", 8, NULL));
	cwd = getcwd(NULL, 1024);
	if (chdir(senv->home) == -1)
		return (ft_cd_error_chdir(&cwd, NULL));
	ft_memdel((void **)&senv->oldpwd);
	senv->oldpwd = ft_strdup(cwd);
	ft_memdel((void **)&cwd);
	if ((get_env_value("OLDPWD")) != NULL)
		set_env_value("OLDPWD", senv->oldpwd);
	set_env_value("PWD", senv->home);
	return (0);
}
