/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:38:56 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:15:30 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
#include "struct.h"

int			test_pipe(t_pipe *pip, char **envp, int *lastcmd)
{
	pid_t	pid;
	int		status;

	if (pip && pip->next)
	{
		pid = process_pipe(pip, envp, 0);
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status))
			(void)status;
		*lastcmd = status;
		while (waitpid(-1, &status, 0) > 0)
			term_initiate();
		return (1);
	}
	return (0);
}

int			ft_apply_cmds(t_op *op)
{
	char	**envp;
	int		cmd;

	cmd = 0;
	envp = env_to_tab();
	while (op)
	{
		if (op->type == 0 || (cmd && op->type == 1) || (!cmd && op->type == 2))
		{
			term_reset();
			if (!test_alone(op->pipe, envp, &cmd))
				test_pipe(op->pipe, envp, &cmd);
			term_initiate();
		}
		op = op->next;
	}
	ft_delfulltab((void ***)&envp);
	return (1);
}

int			main(int argc, char **argv, char **envp)
{
	t_char	*list;
	t_env	**env;

	(void)argc;
	(void)argv;
	list = NULL;
	char_add(&list, char_new('-'));
	*(getactivelist()) = &list;
	env = ft_getenv();
	*env = ft_load_env(envp);
	(ft_saved_env())->home = ft_strdup(get_env_value("HOME"));
	term_initiate();
	ft_putstr_fd("$> ", *(gettty()));
	*(getcurpos()) = 3;
	show_prompt(&list, envp);
	return (0);
}
