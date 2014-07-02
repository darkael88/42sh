/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 06:16:48 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/23 22:24:34 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

void		ft_error_malloc(void)
{
	ft_putendl_fd("error malloc", 2);
	term_terminate(NULL, NULL);
}

int			ft_error_parse(int code, int ret)
{
	if (code == 1)
		ft_putendl_fd("Unmatched .'", 2);
	else if (code == 2)
		ft_putendl_fd("Unmatched .\"", 2);
	else if (code == 3)
		ft_putendl_fd("Invalid null command.", 2);
	else if (code == 4)
		ft_putendl_fd("Missing name for redirect.", 2);
	else if (code == 5)
		ft_putendl_fd("Ambiguous input redirect.", 2);
	else if (code == 6)
		ft_putendl_fd("Ambiguous output redirect.", 2);
	return (ret);
}
