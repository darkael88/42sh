/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_tild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 17:32:29 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:08:55 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <sys/stat.h>
#include <unistd.h>
#include "struct.h"

int					ft_cd_tild(char *str)
{
	t_senv			*senv;
	char			*path;
	int				ret;
	struct stat		filestat;

	filestat.st_mode = S_IFDIR;
	senv = ft_saved_env();
	if (!(senv->home))
		return (ft_error_cd("cd", 5, NULL));
	if (access(senv->home, F_OK) == -1 || access(senv->home, X_OK) == -1)
		return (ft_error_cd("cd", 5, NULL));
	if (lstat(senv->home, &filestat) == -1)
		return (ft_error_cd("cd", 5, NULL));
	path = ft_strjoin(senv->home, &str[1]);
	ret = ft_other_cd(path, 0);
	ft_memdel((void **)&path);
	return (ret);
}
