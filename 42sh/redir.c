/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:37:29 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:28:26 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "shell.h"
#include "struct.h"

void	process_redir_w(t_list_p *item, char **envp)
{
	int		fd;
	int		flags;

	(void)envp;
	flags = O_CREAT | O_WRONLY | O_TRUNC;
	if ((fd = open(item->out, flags, 0644)) == -1)
		ft_error(3);
	if (dup2(fd, 1) == -1)
		ft_error(4);
}

void	process_redir_a(t_list_p *item, char **envp)
{
	int		fd;
	int		flags;

	(void)envp;
	flags = O_CREAT | O_WRONLY | O_APPEND;
	if ((fd = open(item->app, flags, 0644)) == -1)
		ft_error(3);
	if (dup2(fd, 1) == -1)
		ft_error(4);
}

void	process_redir_r(t_list_p *item, char **envp)
{
	int		fd;
	int		flags;

	(void)envp;
	flags = O_RDONLY;
	if ((fd = open(item->in, flags)) == -1)
		ft_error(3);
	if (dup2(fd, 0) == -1)
		ft_error(4);
}
