/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:43:29 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 21:40:08 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	st_test_option(int tmp, int *option)
{
	if (*option == 0)
		*option = tmp;
	else if (tmp == 3)
		*option = tmp;
	else if ((tmp == 1 && *option == 2) || (tmp == 2 && *option == 1))
		*option = 3;
	return (0);
}

int			ft_check_option_echo(char *tab, int *option)
{
	int				i;
	int				tmp;

	i = 1;
	tmp = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] != 'n' && tab[i] != 'E' && tab[i] != 'e')
			return (-1);
		else if (tab[i] == 'n' && tmp == 0)
			tmp = 1;
		else if (tab[i] == 'n' && tmp == 2)
			tmp = 3;
		else if (tab[i] == 'E' && tmp == 0)
			tmp = 2;
		else if (tab[i] == 'E' && tmp == 1)
			tmp = 3;
		i++;
	}
	return (st_test_option(tmp, option));
}

void		ft_echo_check_after_back_slash(char c)
{
	if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'r')
		ft_putchar('\r');
	else
	{
		ft_putchar('\\');
		ft_putchar(c);
	}
}
