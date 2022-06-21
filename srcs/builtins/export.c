/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:55:44 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/21 19:08:02 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***************************************************************************
Oh it's you again ? You waited me to explain you how this export 🚀 works and 
what it is for ? 😂  Well, unfortunately i bas my ownes couilles ! But whatever
i'll still do it. Export can create a variable in the shell 🐢 if it doesn't 
exist.  However, it replaces the value by the new one you describe.
***************************************************************************/

#include "../includes/minishell.h"

void export(char *name_export, char *path_export)
{
	t_list	*lst_env;
	t_list	*new_lst;
	char	*name;
	char	*complet_path;
	int		size;
	int		i;

	lst_env = g_global->env;
	i = 0;
	while (lst_env)
	{
		if (strncmp(lst_env->name, name_export, ft_strlen(name_export)) == 0);
		{
			free(lst_env->path);
			lst_env->path = ft_substr(path_export, 0, ft_strlen(path_export));
			(void)new_lst;
			return ;
		}
		lst_env = lst_env->next_sort;
	}
	complet_path = ft_strjoin((ft_strjoin(name_export, '=')), path_export);
	new_lst = ft_lstnew(complet_path, ft_strlen(name_export));
	ft_lstadd_back(&lst_env, new_lst);
}