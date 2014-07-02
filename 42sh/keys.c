/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 21:13:54 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 16:54:08 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include "shell.h"
#include "struct.h"

static t_tab g_t[21] =
{
	{
		{
			27, 91, 67, 0
		},
		key_right
	},
	{
		{
			27, 91, 68, 0
		},
		key_left
	},
	{
		{
			27, 91, 65, 0
		},
		key_up
	},
	{
		{
			27, 91, 66, 0
		},
		key_down
	},
	{
		{
			50, 67, 0, 0
		},
		key_do_nothing
	},
	{
		{
			50, 68, 0, 0
		},
		key_do_nothing
	},
	{
		{
			27, 27, 91, 67
		},
		key_do_nothing
	},
	{
		{
			27, 27, 91, 68
		},
		key_do_nothing
	},
	{
		{
			27, 91, 72, 0
		},
		key_home
	},
	{
		{
			27, 91, 70, 0
		},
		key_end
	},
	{
		{
			10, 0, 0, 0
		},
		key_enter
	},
	{
		{
			27, 91, 51, 126
		},
		key_delete
	},
	{
		{
			127, 0, 0, 0
		},
		key_delete
	},
	{
		{
			27, 91, 53, 126
		},
		key_do_nothing
	},
	{
		{
			27, 91, 54, 126
		},
		key_do_nothing
	},
	{
		{
			27, 0, 0, 0
		},
		term_terminate
	},
	{
		{
			9, 0, 0, 0
		},
		key_do_nothing
	},
	{
		{
			4, 0, 0, 0
		},
		term_terminate
	},
	{
		{
			8, 0, 0, 0
		},
		key_do_nothing
	},
	{
		{
			11, 0, 0, 0
		},
		key_do_nothing
	},
	{
		{
			12, 0, 0, 0
		},
		key_do_nothing
	},
};

void		test_key(char *rd2, t_char **list, char **envp)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < 21)
	{
		if (rd2[0] == (g_t[i]).rd[0] && rd2[1] == (g_t[i]).rd[1]
			&& rd2[2] == g_t[i].rd[2] && rd2[3] == g_t[i].rd[3])
		{
			ret = g_t[i].fct(list, envp);
			break ;
		}
		i++;
	}
	if (ret == 1)
		return ;
	if (rd2[0] && rd2[1] == 0 && rd2[2] == 0 && rd2[3] == 0)
	{
		char_add(list, char_new(rd2[0]));
		refresh_command_line(list);
	}
	else if (rd2[0] != 27 || rd2[1] != 91 || rd2[2] != 49 || rd2[3] != 59)
		refresh_command_line(list);
}

void		show_prompt(t_char **list, char **envp)
{
	char	rd[4];

	rd[0] = 1;
	while (rd[0] || rd[1] || rd[2] || rd[3])
	{
		sig_set();
		ft_bzero(rd, 4);
		read(0, rd, 4);
		test_key(rd, list, envp);
	}
}
