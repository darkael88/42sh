/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:31:06 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/26 19:05:47 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_senv
{
	char				*oldpwd;
	char				*home;
}						t_senv;

typedef struct			s_char
{
	char				c;
	struct s_char		*prev;
	struct s_char		*next;
}						t_char;

typedef struct			s_copy
{
	t_char				*data;
	t_char				*left;
	t_char				*right;
}						t_copy;

typedef struct			s_list_p
{
	char				*str;
	char				*out;
	char				*app;
	char				*in;
	struct s_list_p		*next;
}						t_list_p;

typedef struct			s_pipe
{
	t_list_p			*list;
	struct s_pipe		*next;
}						t_pipe;

typedef struct			s_op
{
	int					type;
	t_pipe				*pipe;
	struct s_op			*next;
}						t_op;

typedef struct			s_point
{
	t_op				*op;
	struct s_point		*next;
}						t_point;

typedef struct			s_ret
{
	int					ret;
	int					fd;
}						t_ret;

typedef struct			s_andor
{
	int					test;
	int					istrue;
	int					andor;
	int					fd;
	int					fd2;
	int					fd3;
}						t_andor;

typedef struct			s_count
{
	int					i;
	int					j;
	int					k;
	int					l;
	int					check;
}						t_count;

typedef struct s_env	t_env;

struct					s_env
{
	char				*name;
	char				*value;
	t_env				*next;
};

typedef struct			s_argquote
{
	char				**argv;
	int					*argc;
}						t_argq;

typedef struct			s_tab
{
	int					rd[4];
	int					(*fct)(t_char **list, char **envp);
}						t_tab;

typedef struct termios	t_term;

#endif
