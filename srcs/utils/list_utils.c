/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:06:41 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 14:07:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	list_size(t_p *parsed)
{
	int	i;
	t_p	*nav;

	nav = parsed;
	i = 0;
	while (nav)
	{
		i++;
		nav = nav->next;
	}
	return (i);
}

void	free_env(t_c **list)
{
	t_c	*nav;

	if (!(*list))
		return ;
	if ((*list)->next)
		nav = (*list)->next;
	else
	{
		free_tab((*list)->split);
		free(*list);
		return ;
	}
	while (nav->next)
	{
		free_tab(nav->prev->split);
		free(nav->prev);
		nav = nav->next;
	}
	free_tab(nav->prev->split);
	free(nav->prev);
	free_tab(nav->split);
	free(nav);
}

void	normal_add_envp(char *str, t_c **list)
{
	t_c	*nav;
	t_c	*new;

	nav = *list;
	while (nav->next)
		nav = nav->next;
	new = malloc(sizeof(t_c));
	nav->next = new;
	new->split = ft_split_once(str, '=');
	new->next = NULL;
	new->prev = nav;
}

void	add_envp(t_c **list, char *str)
{
	t_c	*new;

	if (!(*list))
	{
		*list = malloc(sizeof(t_p));
		(*list)->split = ft_split_once(str, '=');
		(*list)->next = NULL;
		(*list)->prev = NULL;
	}
	else if (!(*list)->next && !(*list)->prev)
	{
		new = malloc(sizeof(t_p));
		new->split = ft_split_once(str, '=');
		new->next = NULL;
		new->prev = *list;
		(*list)->next = new;
	}
	else
		normal_add_envp(str, list);
}
