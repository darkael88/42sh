/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:47:00 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 09:15:03 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void			ft_put_sign_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
}

static int			ft_power_ten(int n)
{
	unsigned int	number;

	number = 1;
	while (n > 1)
	{
		number = number * 10;
		n--;
	}
	return (number);
}

static int			ft_nbr_nbr(int n)
{
	unsigned int	number;

	number = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		number++;
	}
	number++;
	return (number);
}

static int			ft_least_to_most(int n)
{
	if (n < 0)
		n = -1 * n;
	return (n);
}

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	unsigned int	tmp;
	int				divide;
	char			car;

	number = ft_nbr_nbr(n);
	ft_put_sign_fd(n, fd);
	n = ft_least_to_most(n);
	tmp = n;
	divide = ft_power_ten(number);
	while (number > 0)
	{
		car = tmp / divide + '0';
		write(fd, &car, 1);
		number--;
		tmp = tmp % divide;
		divide = divide / 10;
	}
}
