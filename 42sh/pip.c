/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:33:28 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/26 19:49:25 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	buffer[2048];
	int		nbread;

	fd = open("/dev/ttys007", O_WRONLY | O_CREAT | O_APPEND, 0644);
	write(fd, "\nReading...", 11);
	nbread = read(0, &buffer, 2047);
	buffer[nbread] = '\0';
	write(fd, "\nRead : ", 8);
	write(fd, buffer, nbread);
	write(fd, "\nWriting 'Tatatitatou'...", 25);
	write(1, "Tatatitatou", 11);
	write(fd, "\nExiting...", 11);
	return (0);
}
