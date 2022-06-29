/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:40:01 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/15 18:29:25 jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../includes/libft/libft.h"
# include "../includes/gnl/get_next_line.h"

# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define CONTINUE	2
# define STOP		3

extern struct global *g_glob;

typedef struct global
{
	char	*prompt;
	char	*curr;
	int		in_quotes;
}	t_global;


typedef enum enum_l
{
	BUILTIN = 42,
	BACK_SLASH,
	SLASH,
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
	DOT,
}	t_enum_l;

typedef struct l
{
	char		*str;
	t_enum_l	type;
	struct l	*next;
	struct l	*prev;
}	t_l;

// Prompt functions

char	*create_prompt(void);

// Signal functions

void	ctrl_c(int sig);
void	ctrl_bs(int sig);
void	signal_init(void);

// Lexer functions

int			lexer(char *args);
t_l 		*create_new_elmt(char *str);
t_l			*add_elmt(t_l **elmt, char *str);
t_enum_l	find_type(char *str);
void		handle_chev(char *args, t_l **elmt, int *i);
void		handle_quotes(char *args, t_l **elmt, int *i);
void		general_handler(char *args, t_l **elmt, int *i, int type);
int			type_size(t_l *elmt);
void		end_handler(t_l **elmt);
void		print_list_j(t_l *elmt, int n);

// Parsing functions

int		parser(t_l *elmt);
int		single_one(t_l *elmt);
int		is_pipe(t_l *elmt);

// Builtin functions

void	ft_pwd(void);

// Command functions (execve)

void	execute_commands(char *args);

#endif
