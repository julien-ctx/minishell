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

extern struct global *g_global;

typedef enum e_l_type
{

}	t_l_type
	

typedef struct global
{
	char	*prompt;
}	t_global;

typedef struct plex
{
	char	c;

}	t_plex;

typedef struct lex
{

}	t_lex;

// Prompt functions

char	*create_prompt(void);

// Signal functions

void	ctrl_c(int sig);
void	ctrl_bs(int sig);
void	signal_init(void);

// Lexer functions

void	lexer(char *args);

// Parsing functions

void	parsing(char *args);

// Builtin functions

void	ft_pwd(void);

// Command functions (execve)

void	execute_commands(char *args);

#endif
