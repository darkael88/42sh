/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delfulltab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 15:16:00 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/04 09:10:39 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_delfulltab(void ***tab)
{
	if (tab && *tab)
	{
		ft_memdeltab(tab);
		free(*tab);
		*tab = NULL;
	}
}
