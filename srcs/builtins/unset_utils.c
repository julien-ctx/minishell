/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:45:10 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 13:52:30 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_with_values(t_c *nav)
{
	free_tab(nav->split);
	free(nav);
}

int	unset_flag(char *str)
{
	if (str[0] == '-')
	{
		printf("minishell: unset: options are not handled\n");
		g_glob->code = 1;
		return (1);
	}
	return (0);
}

int	check_unset_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
		{
			printf("minishell: unset: %s: not a valid identifier\n", str);
			g_glob->code = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	unset_empty(t_c **envp)
{
	t_c	*nav;

	nav = *envp;
	if (!nav)
		return (1);
	if (!nav->prev && !nav->next)
	{
		free_with_values(nav);
		g_glob->envp = NULL;
		return (1);
	}
	return (0);
}

void	delete_one_envp(t_c **envp)
{
	t_c	*nav;

	nav = *envp;
	if (unset_empty(envp))
		return ;
	if (!nav->next)
	{
		nav->prev->next = NULL;
		free_with_values(nav);
		return ;
	}
	if (!nav->prev)
	{
		nav->next->prev = NULL;
		g_glob->envp = nav->next;
		free_with_values(nav);
		return ;
	}
	nav->prev->next = nav->next;
	nav->next->prev = nav->prev;
	free_with_values(nav);
}
