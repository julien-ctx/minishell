/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:57:38 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/17 18:23:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/***************************************************************************
Main function to execute right commands with execve function. 
***************************************************************************/
void	execute_commands(char *args)
{
	char	*path;
	char	*argv[2];
	int		pid;
	
	argv[0] = args;
	argv[1] = NULL; 
	pid = fork();
	if (pid == 0)
	{
		path = strjoin_without_free("/bin/", args);
		execve(path, argv, NULL);
		free(path);
	}
	else
		wait(0);
}
