/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 21:29:58 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 16:19:39 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static void		st_exec_test(int fd_in, int fd_out)
{
	if (fd_in != 0 && dup2(fd_in, 0) == -1)
	{
		ft_error(4);
		exit(1);
	}
	if (fd_in != 0 && close(fd_in) == -1)
		ft_error(5);
	if (fd_out != 1)
	{
		if (dup2(fd_out, 1) == -1)
		{
			ft_error(4);
			exit(1);
		}
		if (close(fd_out) == -1)
			ft_error(5);
	}
}

void			execute_son(int fd_in, int fd_out, t_list_p *item, char **envp)
{
	st_exec_test(fd_in, fd_out);
	if (item->in)
		process_redir_r(item, envp);
	else if (item->out)
		process_redir_w(item, envp);
	else if (item->app)
		process_redir_a(item, envp);
	if (!is_built_in(item->str))
		process_command(item->str, envp);
	else if (ft_is_env_i(item->str) > 0)
		process_command((item->str + ft_is_env_i(item->str)), NULL);
	else
		check_built_in(item->str);
	exit(0);
}

static pid_t	proc_pipe_fath(t_pipe *pip, char **envp, int fd[2], pid_t cpid)
{
	pid_t	pid;

	pid = (pid_t)0;
	if (pip->next)
	{
		if (close(fd[1]) == -1)
			ft_error(5);
		pid = process_pipe(pip->next, envp, fd[0]);
		return (pid);
	}
	else
	{
		return (cpid);
	}
}

pid_t			process_pipe(t_pipe *pip, char **envp, int fd_in)
{
	int		fd[2];
	pid_t	process;

	if (pipe(fd) == -1)
		ft_error(6);
	if ((process = fork()) == -1)
		ft_error(7);
	if (process > 0)
		return (proc_pipe_fath(pip, envp, fd, process));
	else if (process == 0)
	{
		if (close(fd[0]) == -1)
			ft_error(5);
		if (pip->next)
			execute_son(fd_in, fd[1], pip->list, envp);
		else
		{
			if (close(fd[1]) == -1)
				ft_error(5);
			execute_son(fd_in, 1, pip->list, envp);
		}
	}
	return (process);
}
