/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:21:49 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/03 22:41:11 by juliencau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_one(char *str)
{
	t_c	*nav;

	nav = g_glob->envp;
	while (nav)
	{
		if (ft_strlen(nav->split[0]) == ft_strlen(str)
			&& !ft_strncmp(nav->split[0], str, ft_strlen(str)))
			delete_one_envp(&nav);
		nav = nav->next;
	}
}

void	unset_all(char **tab)
{
	t_c	*nav;
	int	i;

	i = 1;
	while (tab[i])
	{
		if (check_unset_syntax(tab[i]))
			return ;
		nav = g_glob->envp;
		while (nav)
		{
			if (ft_strlen(nav->split[0]) == ft_strlen(tab[i])
				&& !ft_strncmp(nav->split[0], tab[i], ft_strlen(tab[i])))
			{
				delete_one_envp(&nav);
				break ;
			}
			nav = nav->next;
		}
		i++;
	}
}

void	ft_unset(char **tab)
{
	t_c	*nav;

	nav = g_glob->envp;
	g_glob->code = 0;
	if (!tab[1])
	{
		while (nav)
		{
			if (ft_strlen(nav->split[0]) == 1 && nav->split[0][0] == '_')
				unset_one("_");
			nav = nav->next;
		}
		return ;
	}
	if (unset_flag(tab[1]))
		return ;
	unset_all(tab);
}
