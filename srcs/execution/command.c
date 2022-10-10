/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:49:38 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 11:43:34 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	find_builtin(char **tab)
{
	if (builtin_syntax("echo", tab[0]))
		ft_echo(tab);
	else if (builtin_syntax("exit", tab[0]))
		ft_exit(tab);
	else if (builtin_syntax("pwd", tab[0]))
		ft_pwd(tab);
	else if (builtin_syntax("cd", tab[0]))
		ft_cd(tab);
	else if (builtin_syntax("env", tab[0]))
		ft_env(tab);
	else if (builtin_syntax("export", tab[0]))
		ft_export(tab);
	else if (builtin_syntax("unset", tab[0]))
		ft_unset(tab);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("'%s'\n", tab[i++]);
}

void	execution(char **tab)
{
	if (is_builtin(tab[0]))
		find_builtin(tab);
	else if (already_executable(tab))
		exec_directly(tab);
	else
		find_command(tab);
	free_tab(tab);
}
