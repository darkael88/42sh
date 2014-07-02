/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_alone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:29:55 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 16:48:00 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static void	st_process_zero(t_pipe *pip, char **envp)
{
	if (pip->list->in)
		process_redir_r(pip->list, envp);
	if (pip->list->out)
		process_redir_w(pip->list, envp);
	if (pip->list->app)
		process_redir_a(pip->list, envp);
	if (!is_built_in(pip->list->str))
		process_command(pip->list->str, envp);
	else if (ft_is_env_i(pip->list->str) > 0)
		process_command((pip->list->str + ft_is_env_i(pip->list->str)), NULL);
	else
		check_built_in(pip->list->str);
	exit(0);
}

static void	st_process_dif_zero(int *status, int *lastcmd)
{
	wait(status);
	if (WIFEXITED(*status))
		(void)*status;
	*lastcmd = *status;
}

int			test_alone(t_pipe *pip, char **envp, int *lastcmd)
{
	pid_t	process;
	int		status;

	if (!pip)
		return (0);
	if (pip && !pip->next && pip->list)
	{
		if ((!is_built_in(pip->list->str) || pip->list->in || pip->list->out
				|| pip->list->app)
				|| (is_built_in(pip->list->str) && ft_is_env_i(pip->list->str)))
		{
			process = fork();
			if (process > 0)
				st_process_dif_zero(&status, lastcmd);
			else if (process == 0)
				st_process_zero(pip, envp);
		}
		else
			check_built_in(pip->list->str);
		return (1);
	}
	return (0);
}
