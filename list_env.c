/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:17:47 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/20 18:20:49 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/***************************************************************************
Hi juju, it's Zarley there ! 🐊 This function take the evironnement in form
of char ** and fill a list create for. Cya ! 👋
***************************************************************************/

int	env_size(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

t_list *list_env(char **env)
{
	t_list	*first_lst;
	t_list	*lst_inter;
	int		size_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size_env = env_size(env);
	while (i < size_env)
	{
		while (env[i][j] != '=')
			j++;
		if (first_lst)
		{
			first_lst = ft_lstnew(env[i], j);
			j = 0;
			i++;
			continue ;
		}
		lst_inter = ft_lstnew(env[i], j);
		ft_lstadd_back(&first_lst, lst_inter);
		j = 0;
		i++;
	}
	return (first_lst);
}
