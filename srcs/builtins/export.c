/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:55:44 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/24 15:11:21 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***************************************************************************
Oh it's you again ? You waited me to explain you how this export 🚀 works and 
what it is for ? 😂  Well, unfortunately i bas my ownes couilles ! But whatever
i'll still do it. Export can create a variable in the shell 🐢 if it doesn't 
exist.  However, it replaces the value by the new one you describe.
***************************************************************************/

#include "../../includes/minishell.h"


void	print_list(t_list *list)
{
	t_list *fake;

	fake = list;
	while (fake)
	{
		printf("%s", fake->head);
		printf("%s", fake->name);
		printf("%c", fake->linker);
		printf("%s\n", fake->path);
		fake = fake->next_sort;
	}
}

char	*return_name(char *complet_path)
{
	char	*name;
	int		i;

	i = 0;
	while (complet_path[i] != '=')
		i++;
	name = ft_substr(complet_path, 0, i);
	return (name);
}

char	*return_path(char *complet_path)
{
	char	*path;
	int		i;

	i = 0;
	while (complet_path[i] != '=')
		i++;
	path = ft_substr(complet_path, i + 1, ft_strlen(complet_path));
	return (path);
}

char	*add_on_path(char *complet_path, char *path_export)
{
	int	i;
	char	*path_join;

	i = 0;
	while (complet_path[i] != '=')
		i++;
	i--;
	if (complet_path[i] == '+')
	{
		printf("----------------------c'est vre\n");
		i = i + 2;
		path_join = make_path(ft_strjoin(path_export, ft_substr(complet_path, i, (ft_strlen(complet_path)))));
		return (path_join);
	}
	return (path_export);
			
}

void	export(char *complet_path, t_list *lst_env)
{
	t_list	*new_lst;
	char	*name_export;
	char	*path_export;
	int		i;

	if (!complet_path)
		return ;
	name_export = return_name(complet_path);
	path_export = make_path(return_path(complet_path));
	i = 0;
	while (lst_env)
	{
		if (strncmp(lst_env->name, name_export, ft_strlen(name_export)) == 0)
		{
			free(lst_env->path);
			lst_env->path = add_on_path(complet_path, path_export);
			(void)new_lst;
			return ;
		}
		lst_env = lst_env->next_sort;
	}
	new_lst = ft_lstnew(complet_path, ft_strlen(name_export));
	ft_lstadd_back(&g_global->env, new_lst);
	sort_list(&g_global->env);
}

int main (int argc, char **argv, char **env)
{
	(void)argc;
	t_list	*list;
	return_list(env);
	list = g_global->env;
	char *complet_path = argv[1];
	export(complet_path, list);
	list = g_global->env;
	print_list(list);
//	while(1);
//	export(complet_path);	
}