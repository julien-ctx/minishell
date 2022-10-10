/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:44:47 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 13:44:48 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_c	*dup_env(void)
{
	t_c		*dup;
	t_c		*nav;
	char	*str;

	dup = NULL;
	nav = g_glob->envp;
	str = NULL;
	while (nav)
	{
		if (nav->split[0])
			str = ft_strdup(nav->split[0]);
		if (nav->split[1])
		{
			str = ft_strjoin(str, "=");
			if (nav->split[1][0])
				str = ft_strjoin(str, nav->split[1]);
		}
		add_envp(&dup, str);
		free(str);
		str = NULL;
		nav = nav->next;
	}
	return (dup);
}

t_c	*sorted_env(void)
{
	t_c		*dup;
	t_c		*nav;
	t_c		*nav_2;
	char	**tmp;

	dup = dup_env();
	nav_2 = dup;
	while (nav_2)
	{
		nav = dup->next;
		while (nav)
		{
			if (ft_strcmp(nav->prev->split[0], nav->split[0]) > 0)
			{
				tmp = nav->prev->split;
				nav->prev->split = nav->split;
				nav->split = tmp;
			}
			nav = nav->next;
		}	
		nav_2 = nav_2->next;
	}
	return (dup);
}

int	small_export(void)
{
	if (!g_glob->envp)
		return (1);
	else if (!g_glob->envp->next && !g_glob->envp->prev)
	{
		if (!g_glob->envp->split[1])
			printf("declare -x %s\n", g_glob->envp->split[0]);
		else
			printf("declare -x %s=\"%s\"\n", g_glob->envp->split[0],
				g_glob->envp->split[1]);
		return (1);
	}
	return (0);
}

void	print_env(void)
{
	t_c	*nav;

	nav = g_glob->envp;
	while (nav)
	{
		if (nav->split[1])
		{
			if (!nav->split[1][0])
				printf("%s=\n", nav->split[0]);
			else
				printf("%s=%s\n", nav->split[0], nav->split[1]);
		}
		nav = nav->next;
	}
}

void	print_export(void)
{
	t_c	*sorted;
	t_c	*nav;

	if (small_export())
		return ;
	sorted = sorted_env();
	nav = sorted;
	while (nav)
	{
		if (!nav->split[1])
			printf("declare -x %s\n", nav->split[0]);
		else if (!nav->split[1][0])
			printf("declare -x %s=\"\"\n", nav->split[0]);
		else
			printf("declare -x %s=\"%s\"\n", nav->split[0], nav->split[1]);
		nav = nav->next;
	}
	free_env(&sorted);
}
