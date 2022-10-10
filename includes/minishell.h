/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:33:30 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 14:11:16 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../includes/libft/libft.h"

# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include <termios.h>
# include <fcntl.h>

# define NO			0
# define YES		1
# define CONTINUE	2
# define STOP		3
# define FREE		4

extern struct global	*g_glob;

typedef struct c
{
	struct c	*next;
	struct c	*prev;
	char		**split;
}	t_c;

typedef struct global
{
	t_c		*envp;
	char	*prompt;
	char	*curr;
	int		q_type;
	int		code;
	int		stty;
}	t_global;

typedef enum enum_type
{
	BUILTIN = 48,
	EXEC,
	DOLLAR,
	PIPE,
	R_CHEV,
	L_CHEV,
	R_DCHEV,
	L_DCHEV,
	QUOTE,
	D_QUOTE,
	TEXT,
	WHITE_SPACE,
	IN_D_QUOTES,
	OUT_D_QUOTES,
	IN_QUOTES,
	USELESS,
	R_CHEV_L,
	L_CHEV_L,
	R_DCHEV_L,
	L_DCHEV_L
}	t_enum_type;

typedef struct l
{
	char		*str;
	t_enum_type	type;
	struct l	*next;
	struct l	*prev;
}	t_l;

typedef struct p
{
	char		*str;
	t_enum_type	type;
	struct p	*next;
	struct p	*prev;
}	t_p;

typedef struct fd
{
	int			stdin_mem;
	int			stdout_mem;
	int			stderr_mem;
	int			fd_in;
	int			fd_out;
	int			curr_fd;
	t_enum_type	type;
}	t_fd;

// Signal functions

void		ctrl_c(int sig);
void		ctrl_bs(int sig);
void		signal_init(void);
int			exit_code(int status);

// Lexer functions

void		lexer(char *args);
t_l			*create_new_elmt(char *str);
t_l			*add_elmt_l(t_l **elmt, char *str);
t_enum_type	find_type(char *str);
void		handle_chev(char *args, t_l **elmt, int *i);
void		handle_quotes(char *args, t_l **elmt, int *i);
void		general_handler(char *args, t_l **elmt, int *i, int type);
void		end_handler(t_l **elmt);
int			is_builtin(char *str);
int			is_exec(char *str);
void		free_lexed(t_l **lexed);
char		*var_handling(char *args);

// Checker functions

int			not_only_spaces(char *args);

// Parsing functions

void		parser(t_l *elmt);
int			single_one(t_l *elmt);
int			is_pipe(t_l *elmt);
void		add_elmt_p(t_p **parsed, char *str);
int			quote_handling(t_l *elmt, t_p **parsed);
void		find_next_quote(t_l **nav, t_l *elmt, t_p **parsed);
void		free_parsed(t_p **parsed);
int			pipe_handling(t_p **parsed);
void		add_elmt_type(t_p **parsed, char *str, int type);
void		q_tokens_handler(t_p **parsed);
t_p			*parsed_init(void);
void		add_elmt_type(t_p **parsed, char *str, int type);

// Redirections functions

void		redirections(t_p **parsed);
int			check_r_syntax(t_p **parsed);
int			is_redirection(t_p *nav);
void		redirections_setup(t_p **parsed);
t_fd		mem_fds(void);
void		change_t_p(t_p	**parsed, int i);
int			heredoc_handler(t_p **parsed, t_fd *fds);
void		input_handler(t_p **parsed, t_fd *fds, int i);
void		output_handler(t_p **parsed, t_fd *fds);
t_p			*recreate_and_exec(t_p **parsed, int i);
t_p			*new_parsed(t_p **parsed);
char		**recreate_parsed(t_p *parsed);

// Builtin functions

char		*find_path(char *str);
void		print_export(void);
void		print_env(void);
int			ft_echo(char **tab);
int			ft_exit(char **tab);
int			ft_cd(char **tab);
void		ft_pwd(char **tab);
void		ft_env(char **tab);
void		ft_unset(char **tab);
int			ft_export(char **tab);
int			return_not_set(char *new);
void		delete_one_envp(t_c **envp);
int			check_unset_syntax(char *str);
int			unset_flag(char *str);
void		free_with_values(t_c *nav);
int			export_alone(void);
int			export_error(char *str);
int			var_error(char *str);
void		replace_curr_path(int i, char *str, t_c **nav);

// Exec functions

void		envp_init(char **env);
void		set_escape_handling(void);
void		unset_escape_handling(void);
void		execution(char **tab);
void		find_command(char **tab);
void		print_tab(char **tab);
char		**generate_envp(void);
int			already_executable(char **tab);
void		exec_directly(char **tab);

// List utils

void		add_envp(t_c **list, char *str);
void		free_env(t_c **list);
int			list_size(t_p *parsed);

// Utils

void		free_tab(char **tab);
int			tab_only_spaces(char *tab);
int			builtin_syntax(char *ref, char *str);

#endif
