/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:45:43 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:29:52 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "shell.h"
#include "struct.h"

int		*gettty(void)
{
	static int		*fdtty = NULL;

	if (fdtty == NULL)
	{
		fdtty = (int *)malloc(sizeof(int));
		*fdtty = open("/dev/tty", O_RDWR);
	}
	return (fdtty);
}
