/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:27:07 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/05 10:27:32 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putstr_fd(char const *s, int fd)
{
	size_t		size;

	if (s)
	{
		size = ft_strlen(s);
		write(fd, s, size);
	}
}
