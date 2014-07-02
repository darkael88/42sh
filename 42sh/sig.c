/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 19:22:41 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 19:17:30 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include "shell.h"

void				sig_callback(int sig)
{
	if (sig == 6 || sig == 3 || sig == 15 || sig == 1)
		term_terminate(NULL, NULL);
	else if (sig == 2)
	{
	}
}

void				sig_set(void)
{
	signal(SIGABRT, sig_callback);
	signal(SIGQUIT, sig_callback);
	signal(SIGTERM, sig_callback);
	signal(SIGHUP, sig_callback);
	signal(SIGINT, sig_callback);
	signal(SIGTSTP, SIG_IGN);
}
