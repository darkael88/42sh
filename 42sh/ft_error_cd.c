/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 13:16:48 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 15:44:18 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_error_cd(char *cmd, int code, char *dir)
{
	ft_putstr_fd(cmd, 2);
	if (code == 1)
		ft_putstr_fd(": No such file or directory: ", 2);
	else if (code == 2)
		ft_putstr_fd(": Permission denied: ", 2);
	else if (code == 3)
		ft_putstr_fd(": Not a directory: ", 2);
	else if (code == 4)
		ft_putstr_fd(": Too many arguments.", 2);
	else if (code == 5)
		ft_putstr_fd(": Can't change to home directory.", 2);
	else if (code == 6)
	{
		ft_putendl_fd(": No such file or directory.", 2);
		return (1);
	}
	else if (code == 7)
		ft_putstr_fd(": Permission denied.", 2);
	else if (code == 8)
		ft_putstr_fd(": Not a directory.", 2);
	ft_putendl_fd(dir, 2);
	return (1);
}
