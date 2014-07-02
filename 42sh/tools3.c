/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 18:17:00 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:39:15 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include "shell.h"

int		get_num_cols(void)
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	return ((int)(size.ws_col));
}

int		get_num_rows(void)
{
	struct winsize	size;

	ioctl(0, TIOCGWINSZ, &size);
	return ((int)(size.ws_row));
}

t_char	**getactivechar(void)
{
	static t_char	*active = NULL;

	return (&active);
}

t_char	**getactivehistory(void)
{
	static t_char	*active = NULL;

	return (&active);
}

int		*getcurpos(void)
{
	static int		pos = 0;

	return (&pos);
}
