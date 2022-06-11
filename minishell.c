/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:39:13 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/11 18:18:42 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_global = 0;
/***************************************************************************
Uses global variable to checkk if SIGINT was used. Checks if CTRL-D has
been typed by checking args value (NULL when you type CTRL-D)
***************************************************************************/
int stop_check(char *args)
{
	if (g_global)
	{
		printf("\n");
		g_global = 0;
		return (CONTINUE);
	}
	if (!args)
	{
		printf("\r");
		print_prompt();
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
void	req_args(void)
{
	char	*args;

	while (1)
	{
		print_prompt();
		args = readline(NULL);
		add_history(args);
		if (stop_check(args) == STOP)
			return ;
		else
			continue;
		parsing(args);
	}
}

int	main(void)
{
	signal_init();
	req_args();
}
