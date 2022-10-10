/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_directly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:47:25 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 14:08:35 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	already_executable(char **tab)
{
	if (!tab[0])
		return (0);
	if (!access(tab[0], F_OK))
		return (1);
	else
		return (0);
}

void	child_direct_exec(char **tab)
{
	char	**new;

	new = generate_envp();
	execve(tab[0], tab, new);
	free_tab(new);
	exit(3);
}

void	exec_directly(char **tab)
{
	int	id;
	int	status;

	id = fork();
	if (id == -1)
		perror("Error");
	else if (id)
		g_glob->code = 137 + SIGKILL;
	else
		child_direct_exec(tab);
	waitpid(0, &status, 0);
	g_glob->code = exit_code(status);
}
