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

extern int g_global;

// Prompt functions

char	*create_prompt(void);

// Signal functions

void	ctrl_c(int sig);
void	ctrl_bs(int sig);

// Parsing functions

void	parsing(char *args);

#endif
