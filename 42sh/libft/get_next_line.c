/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 13:38:54 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 17:55:06 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int			ft_check_end(char **end, char **line)
{
	char			*new_end;
	char			*new_line;

	if (!end)
		return (0);
	if (ft_chrsplit(*end, '\n', &new_line, &new_end))
	{
		if (new_end)
		{
			free(*end);
			*end = new_end;
		}
		else
			ft_memdel((void **)end);
		*line = new_line;
		return (1);
	}
	return (0);
}

static int			ft_check_line(char **end, char **buf, char **line)
{
	char			*tmp;

	tmp = ft_strjoin(*end, *buf);
	free(*end);
	*end = tmp;
	return (ft_check_end(end, line));
}

int					get_next_line(int const fd, char **line)
{
	static char		*end = NULL;
	char			*buf;
	int				ret;

	if (fd < 0 && BUFF_SIZE < 1 && BUFF_SIZE > 2000000000)
		return (-1);
	if (ft_check_end(&end, line) == 1)
		return (1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ft_check_line(&end, &buf, line) == 1)
		{
			ft_memdel((void **)&buf);
			return (1);
		}
	}
	if (*buf)
		ft_memdel((void **)&buf);
	*line = ft_strdup(end);
	ft_memdel((void **)&end);
	return (ret);
}
