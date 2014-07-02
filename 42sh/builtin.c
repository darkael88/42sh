/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:13:01 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 19:15:30 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
#include "struct.h"

static int	st_clean_args(char ***args, int ret)
{
	ft_delfulltab((void ***)args);
	return (ret);
}

int			is_built_in(char *line)
{
	char	**args;

	args = ft_strsplit(line, ' ');
	if (!args || !args[0])
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "history") == 0)
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "env") == 0)
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "setenv") == 0)
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "cd") == 0)
		return (st_clean_args(&args, 1));
	else if (ft_strcmp(args[0], "echo") == 0)
		return (st_clean_args(&args, 1));
	else
		return (st_clean_args(&args, 0));
	return (st_clean_args(&args, 1));
}

int			check_built_in(char *line)
{
	char	**args;

	args = ft_strsplit(line, ' ');
	if (!args || !args[0])
		ft_errorprompt("[Errorprompt]");
	else if (ft_strcmp(args[0], "exit") == 0)
		term_terminate(NULL, NULL);
	else if (ft_strcmp(args[0], "history") == 0)
		display_history();
	else if (ft_strcmp(args[0], "env") == 0)
		ft_display_env();
	else if (ft_strcmp(args[0], "setenv") == 0)
		ft_set_env(args);
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		ft_unset_env(args);
	else if (ft_strcmp(args[0], "cd") == 0)
		ft_cd(args);
	else if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else
		return (st_clean_args(&args, 0));
	ft_delfulltab((void ***)&args);
	return (1);
}
