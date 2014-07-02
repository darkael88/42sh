/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:16:58 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 00:31:26 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

void	ft_errorexit(char *errormsg)
{
	ft_putstr_fd(errormsg, 2);
	term_terminate(NULL, NULL);
}

void	ft_errorprompt(char *errormsg)
{
	ft_putstr_fd(errormsg, 2);
	ft_putstr("$> ");
}

void	ft_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Error : unable to malloc\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error : cannot create path\n", 2);
	else if (error == 3)
		ft_putstr_fd("Error : cannot open file\n", 2);
	else if (error == 4)
		ft_putstr_fd("Error : Failed to duplicate fd\n", 2);
	else if (error == 5)
		ft_putstr_fd("Error : cannot close file\n", 2);
	else if (error == 6)
		ft_putstr_fd("Error : pipe process failure !\n", 2);
	else if (error == 7)
		ft_putstr_fd("Error : cannot fork\n", 2);
	else if (error == 8)
		ft_putstr_fd("Error : wrong parameters\n", 2);
	else if (error == 9)
	{
		ft_putstr_fd(": command not found\n", 2);
		exit(1);
	}
	else if (error == 0)
		ft_putstr_fd("/!\\ ERROR /!\\\n", 2);
	term_terminate(NULL, NULL);
}

char	*remove_lrspaces(char *str, int max)
{
	int		end;
	int		start;

	start = 0;
	end = 0;
	while (str[start] && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (str[end] && end < max)
		end++;
	end--;
	while (end >= 0 && (str[end] == ' ' || str[end] == '\t'))
		end--;
	if ((end + 1) <= start)
		return (NULL);
	return (ft_strndup((str + start), (end + 1) - start));
}

int		ft_charcmp(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
