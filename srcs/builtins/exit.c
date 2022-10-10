/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:37:33 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 15:12:01 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_and_exit(int n, int print)
{
	if (print)
		printf("exit\n");
	if (n >= 0 && n <= 255)
	{
		g_glob->code = n;
		free_env(&g_glob->envp);
		free(g_glob);
		exit(n);
	}
	else
	{
		g_glob->code = n % 256;
		free_env(&g_glob->envp);
		free(g_glob);
		exit(n % 256);
	}
}

int	syntax_exit_ok(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if ((str[i] >= 48 && str[i] <= 57) || (str[i] == '-') || (str[i] == '+'))
		i++;
	else
		return (0);
	while (str[i])
	{
		if ((str[i] > 57) || (str[i] < 48))
			return (0);
		i++;
	}
	return (1);
}

void	free_and_exit(int n)
{
	g_glob->code = n;
	exit(n);
}

int	ft_exit(char **tab)
{
	int	i;
	int	n;

	i = 1;
	if (!tab[i])
		return (print_and_exit(0, 0));
	if (tab[i + 1])
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		free_and_exit(1);
	}
	if (!syntax_exit_ok(tab[i]))
	{
		printf("exit\n");
		printf("minishell: exit: numeric argument required\n");
		free_and_exit(255);
	}
	n = ft_atoi(tab[i]);
	print_and_exit(n, 1);
	return (1);
}
