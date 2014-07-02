/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 21:01:49 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 19:52:40 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			st_check_echo_parse_base(char *str, int *i, int *status)
{
	if ((*status == 1 && str[*i] == '\'') || (*status == 2 && str[*i] == '"'))
		*status = 0;
	else if (*status > 0 && str[*i] == '\\')
	{
		(*i)++;
		ft_echo_check_after_back_slash(str[*i]);
	}
	else if (*status == 0 && str[*i] == '\'')
		*status = 1;
	else if (*status == 0 && str[*i] == '"')
		*status = 2;
	else if (*status == 0 && str[*i] == '\\')
	{
		(*i)++;
		if (str[*i] == '\\')
		{
			(*i)++;
			ft_echo_check_after_back_slash(str[*i]);
		}
		else
			ft_putchar(str[*i]);
	}
	else
		ft_putchar(str[*i]);
}

static void			st_print_after_back_slash(int *i, char *str)
{
	ft_putchar('\\');
	(*i)++;
	ft_putchar(str[*i]);
}

static void			st_check_echo_parse_esc(char *str, int *i, int *status)
{
	if ((str[*i] == '\'' && *status == 1) || (*status == 2 && str[*i] == '"'))
		*status = 0;
	else if (*status == 0 && str[*i] == '\'')
		*status = 1;
	else if (*status == 0 && str[*i] == '"')
		*status = 2;
	else if (*status == 1)
		ft_putchar(str[*i]);
	else if (*status == 2 && str[*i] == '\\' && str[*i + 1] != '\'')
		st_print_after_back_slash(i, str);
	else if (*status == 2 && str[*i] == '\\' && str[*i + 1] == '\'')
	{
		(*i)++;
		ft_putchar(str[*i]);
	}
	else if (*status == 0 && str[*i] == '\\')
	{
		(*i)++;
		ft_putchar(str[*i]);
	}
	else
		ft_putchar(str[*i]);
}

static void			st_check_str_echo(char *tab, int option)
{
	int				status;
	int				i;

	i = 0;
	status = 0;
	if (option == 0 || option == 1)
	{
		while (tab[i] != '\0')
		{
			st_check_echo_parse_base(tab, &i, &status);
			if (tab[i] != '\0')
				i++;
		}
	}
	else
	{
		while (tab[i] != '\0')
		{
			st_check_echo_parse_esc(tab, &i, &status);
			if (tab[i] != '\0')
				i++;
		}
	}
}

int					ft_echo(char **tab)
{
	int				i;
	int				option;

	option = 0;
	if ((ft_tablen((void **)tab)) > 1)
	{
		i = 1;
		while (tab[i] && tab[i][0] == '-')
		{
			if (ft_check_option_echo(tab[i], &option) == -1)
				break ;
			i++;
		}
		if (!tab[i] && (option == 1 || option == 3))
			return (1);
		while (tab[i])
		{
			st_check_str_echo(tab[i], option);
			i++;
			if (tab[i])
				ft_putchar(' ');
		}
	}
	return (ft_echo_end(option));
}
