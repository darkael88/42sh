/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:17:46 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 18:23:31 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strglue(char const *s1, char const *glue, char const *s2)
{
	char	*temp;
	int		length;

	if (!s1 || !glue || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(glue) + ft_strlen(s2);
	if (!(temp = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	temp[0] = '\0';
	ft_strcat(temp, s1);
	ft_strcat(temp, glue);
	ft_strcat(temp, s2);
	temp[length] = '\0';
	return (temp);
}
