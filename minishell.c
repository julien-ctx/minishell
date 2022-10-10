/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:17:23 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 15:35:05 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_global	*g_glob;

int	return_and_free(void)
{
	free(g_glob->prompt);
	return (STOP);
}

/***************************************************************************
Uses global variable to checkk if SIGINT was used. Checks if CTRL-D has
been typed by checking args value (NULL when you type CTRL-D)
***************************************************************************/
int	stop_check(char *args, char *prompt)
{
	if (!args)
	{
		if (!g_glob->envp)
			ft_putstr_fd("\n\033[1A", 1);
		else
			ft_putstr_fd("\033[1A", 1);
		ft_putstr_fd(prompt, 1);
		ft_putstr_fd("exit\n", 1);
		g_glob->code = 0;
		free_env(&g_glob->envp);
		free(g_glob);
		exit(0);
		return (STOP);
	}
	else if ((!strncmp(args, "exit", 4) && ft_strlen(args) == 4))
	{
		g_glob->code = 0;
		free_env(&g_glob->envp);
		free(g_glob);
		exit(0);
		return (STOP);
	}
	return (CONTINUE);
}

int	empty_args(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((args[i] != ' ') && ((args[i] < 9) || (args[i] > 13)))
			return (0);
		i++;
	}
	return (1);
}

/***************************************************************************
Main loop to retrieve arguments and then use the parser or display an error
message on the terminal and terminate the session
***************************************************************************/
int	req_args(void)
{
	char	*args;

	while ("Minishell Sardou")
	{
		g_glob->prompt = ft_strdup("minishell$ ");
		unset_escape_handling();
		args = readline(g_glob->prompt);
		set_escape_handling();
		if (ft_strlen(args) && not_only_spaces(args))
			add_history(args);
		if (stop_check(args, g_glob->prompt) == STOP)
		{
			free(args);
			return (return_and_free());
		}
		free(g_glob->prompt);
		if (empty_args(args))
		{
			free(args);
			continue ;
		}
		lexer(args);
		free(args);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_glob = malloc(sizeof(t_global));
	if (!g_glob)
		return (1);
	g_glob->envp = NULL;
	g_glob->code = 0;
	signal_init();
	envp_init(env);
	req_args();
	free(g_glob);
	return (0);
}
