/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:39:13 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/22 15:58:50 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_global *g_glob;

int	return_and_free(void)
{
	free(g_glob->prompt);
	return (STOP);
}

/***************************************************************************
Uses global variable to checkk if SIGINT was used. Checks if CTRL-D has
been typed by checking args value (NULL when you type CTRL-D)
***************************************************************************/
int stop_check(char *args, char *prompt)
{
	if (!args)
	{
		write (1, "\r", 1);
		printf("%s", prompt);
		printf("exit\n");
		return (STOP);
	}
	if (!strncmp(args, "exit", 4) && ft_strlen(args) == 4)
		return (STOP);
	return (CONTINUE);
}

/***************************************************************************
Main loop to retrieve arguments and then use the parser or display an error
message on the terminal and terminate the session
***************************************************************************/
int	req_args(void)
{
	char	*args;

	while (1)
	{
		g_glob->prompt = create_prompt();
		args = readline(g_glob->prompt);	
		if (ft_strlen(args))
			add_history(args);
		if (stop_check(args, g_glob->prompt) == STOP)
			return(return_and_free());
		free(g_glob->prompt);
		lexer(args);
	}
}

int	main(void)
{
	g_glob = malloc(sizeof(t_global));
	signal_init();
	req_args();
	free(g_glob);
	return (0);
}
