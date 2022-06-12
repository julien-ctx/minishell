/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:39:13 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/12 17:05:27 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_global = 0;

int	return_and_free(char *prompt)
{
	free(prompt);
	return (STOP);
}

/***************************************************************************
Uses global variable to checkk if SIGINT was used. Checks if CTRL-D has
been typed by checking args value (NULL when you type CTRL-D)
***************************************************************************/
int stop_check(char *args, char *prompt)
{
	if (g_global)
	{
		printf("\n\n");
		g_global = 0;
		return (CONTINUE);
	}
	if (!args)
	{
		printf("\r");
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
	char	*prompt;

	while (1)
	{
		prompt = create_prompt();
		args = readline(prompt);	
		if (ft_strlen(args))
			add_history(args);
		if (stop_check(args, prompt) == STOP)
			return(return_and_free(prompt));
		else
			continue;
		free(prompt);
		parsing(args);
	}
}

int	main(void)
{
	signal(SIGINT, ctrl_c);
	req_args();
}
