/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenoit <dbenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:40:04 by dbenoit           #+#    #+#             */
/*   Updated: 2014/03/27 22:19:53 by dbenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# include "struct.h"

# define MAXHISTORY		10
# define AND			(3)
# define OR				(4)

char	**get_pathlist(void);
t_env	**ft_getenv(void);
t_env	*env_new(char *name, char *value);
void	env_add(t_env **list, t_env *item);
void	env_delete(t_env **list, t_env *item);
char	**split_env(char *str);
t_env	*ft_load_env(char **envp);
int		ft_display_env(void);
int		ft_set_env(char **args);
int		ft_unset_env(char **args);
char	*get_env_value(char *name);
int		set_env_value(char *name, char *value);
char	**env_to_tab(void);

void	ft_errorexit(char *errormsg);
void	ft_error(int error);
void	ft_errorprompt(char *errormsg);
int		ft_charcmp(char c, char *str);

void	term_initiate(void);
void	term_reset(void);
int		term_terminate(t_char **list, char **envp);

int		*gettty(void);

int		key_right(t_char **list, char **envp);
int		key_left(t_char **list, char **envp);
int		key_alt_right(t_char **list, char **envp);
int		key_alt_left(t_char **list, char **envp);
int		key_shift_right(t_char **list, char **envp);
int		key_shift_left(t_char **list, char **envp);
int		key_home(t_char **list, char **envp);
int		key_end(t_char **list, char **envp);
int		key_up(t_char **list, char **envp);
int		key_down(t_char **list, char **envp);
int		key_enter(t_char **list, char **envp);
int		key_delete(t_char **list, char **envp);
int		key_alt_c(t_char **list, char **envp);
int		key_alt_v(t_char **list, char **envp);
int		key_do_nothing(t_char **list, char **envp);
void	test_key(char *rd, t_char **list, char **envp);

void	show_prompt(t_char **list, char **envp);

int		t_write(int c);

t_char	*char_new(char c);
void	char_add(t_char **first, t_char *item);
t_char	*char_delete(t_char **first, t_char *item);
char	*char_to_str(t_char *list);
t_char	*char_dup(t_char *list);
void	char_wipe(t_char **list);
t_char	*char_insert_after(t_char *after, t_char *item);
t_char	**getactivechar(void);
t_char	**move_active_char_back();

t_char	**gethistory(void);
t_char	**getactivehistory();
void	add_history(t_char *list);
void	display_history(void);
t_char	***getactivelist(void);

int		get_num_cols(void);
int		get_num_rows(void);

int		*getcurpos();
void	cursor_go_to(int num);
void	cursor_move_right(int num);
void	cursor_move_left(int num);

void	clear_command_line(t_char *list);
void	refresh_command_line(t_char **list);

void	sig_set(void);
void	sig_callback(int sig);

t_copy	*getcp(void);
void	cp_copy(void);
void	cp_paste(t_char **list);
void	cp_refresh(t_char *tchar);
int		cp_reset(int mode);

char	*ft_strglue(char const *s1, char const *glue, char const *s2);
char	*ft_strndup(const char *s1, size_t n);

int		ft_status_zero(t_list_p **list, int *status, int *left, int *right);
int		ft_parse_red(t_point *list);
void	ft_separate_op(t_op *op);
void	ft_separate_pipe(t_pipe *pipe);
void	ft_separate_tpoint(t_point *list);
void	ft_send_parse_cmd(t_point *list);
int		ft_check_error_parse(t_list_p *list, int status, int left, int right);
int		ft_error_parse(int code, int ret);
int		ft_parse_str(const char *str, t_list_p **begin, int i, int status);
void	ft_del_full_point(t_point **begin);
void	ft_push_tlist(const char *str, t_list_p **begin, int *start, int *end);
t_pipe	*ft_create_tpipe(t_list_p *ref);
t_op	*ft_create_t_op(t_list_p *ref);
t_point	*ft_create_tpoint(t_list_p *ref);
int		ft_parse(const char *str);
int		ft_check_error_parse_red(t_point *list);

void	ft_error_malloc(void);

t_senv	*ft_saved_env(void);
int		ft_cd_home(void);
int		ft_cd_least(void);
int		ft_cd_tild(char *str);
int		ft_cd(char **tab);
int		ft_error_cd(char *cmd, int code, char *dir);
int		ft_cd_error_chdir(char **tmp, char **pwd);
int		ft_cmd_error(char *arg1, char *arg2, char *arg3);
int		ft_other_cd(char *path, int option);

char	*ft_parse_arg_env(char *src);

int		ft_echo(char **tab);
int		ft_echo_end(int option);
int		ft_check_option_echo(char *tab, int *option);
void	ft_echo_check_after_back_slash(char c);

void	ft_exit(void);

int		ft_apply_cmds(t_op *op);
void	execute_father(int fd, t_list_p *item, char **envp);
void	execute_son(int fd_in, int fd_out, t_list_p *item, char **envp);
int		is_built_in(char *line);
int		check_built_in(char *line);
int		test_alone(t_pipe *pip, char **envp, int *lastcmd);
int		test_pipe(t_pipe *pip, char **envp, int *lastcmd);
pid_t	process_pipe(t_pipe *pip, char **envp, int fd_in);
void	process_redir_w(t_list_p *item, char **envp);
void	process_redir_a(t_list_p *item, char **envp);
void	process_redir_r(t_list_p *item, char **envp);
void	process_command(char *line, char **envp);
char	**ft_strsplit_cmd(char *src);

int		ft_is_env_i(char *str);
int		ft_is_env(char *str);

#endif
