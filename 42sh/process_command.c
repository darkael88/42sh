/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:13:51 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 23:03:37 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include <unistd.h>

static void		st_search_pathlist(char **args, char **pathlist, int *j,
									char **envp)
{
	execve(ft_strglue(pathlist[*j], "/", args[0]), args, envp);
	(*j)++;
}

static void		st_execve(char ***args, char **envp)
{
	char		**pathlist;
	int			j;

	j = 0;
	if (ft_strlen((*args)[0]) > 2 && ft_strstr((*args)[0], "./") == (*args)[0])
		execve((*args)[0], *args, envp);
	if (ft_strlen((*args)[0]) > 1 && *args[0][0] == '/')
		execve((*args)[0], *args, envp);
	pathlist = get_pathlist();
	while (pathlist[j])
		st_search_pathlist(*args, pathlist, &j, envp);
	ft_delfulltab((void ***)&pathlist);
}

void			process_command(char *line, char **envp)
{
	char		**args;

	if (!line)
		exit(1);
	if (!is_built_in(line))
	{
		args = ft_strsplit_cmd(line);
		if (args && ft_strncmp(args[0], "./", 2) == 0
			&& access(args[0], F_OK) == 0 && access(args[0], X_OK) == -1)
		{
			ft_error_cd(args[0], 7, NULL);
			ft_putchar('\n');
			ft_delfulltab((void ***)&args);
			exit(1);
		}
		st_execve(&args, envp);
		if (args)
			ft_delfulltab((void ***)&args);
		ft_putstr_fd(line, 2);
		ft_error(9);
	}
	else
		check_built_in(line);
	exit(1);
}
