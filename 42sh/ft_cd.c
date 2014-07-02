/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 13:12:50 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/27 15:45:39 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_senv		*ft_saved_env(void)
{
	static t_senv	saveenv = {NULL, NULL};

	return (&saveenv);
}

static int	st_check_arg(char *tab, int *status)
{
	int		i;

	if (tab && tab[0] != '-')
		return (2);
	i = 1;
	*status = 0;
	while (tab && tab[i] != '\0' && (tab[i] == 'P' || tab[i] == 'L'))
	{
		if (tab[i] == 'P')
			*status = 2;
		if (tab[i] == 'L')
			*status = 1;
		i++;
	}
	if (*status != 0)
		return (0);
	else
		return (1);
}

static int	st_check_option(char **tab)
{
	int		y;
	int		ret;
	int		status;
	int		fstatus;

	y = 0;
	status = 0;
	while (tab[y])
	{
		fstatus = 0;
		ret = st_check_arg(tab[y], &status);
		if (ret == 0 && st_check_arg(tab[y + 1], &fstatus) != 0)
			return (ft_other_cd(tab[y + 1], status));
		y++;
	}
	return (ft_cd_home());
}

int			ft_cd(char **tab)
{
	if (ft_tablen((void **)tab) == 1)
		return (ft_cd_home());
	else if (tab[1][0] == '~')
		return (ft_cd_tild(tab[1]));
	else if (tab[1][0] == '-')
	{
		if (tab[1][1] != '\0')
			return (st_check_option(&tab[1]));
		else
			return (ft_cd_least());
	}
	else if (ft_tablen((void **)tab) > 2)
		return (ft_error_cd("cd", 4, NULL));
	else
		return (ft_other_cd(tab[1], 0));
	return (0);
}
