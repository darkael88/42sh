/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_least.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 18:38:21 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 18:08:39 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "struct.h"

int			ft_cd_least(void)
{
	t_senv	*senv;
	int		ret;

	senv = ft_saved_env();
	ret = ft_other_cd(senv->oldpwd, 0);
	return (ret);
}
