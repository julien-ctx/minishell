/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:01:20 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 15:25:36 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	curr_var_replacing(int i, char *str, t_c *nav, char *name)
{
	if (name)
		free(name);
	replace_curr_path(i, str, &nav);
}

int	existing_var(char *str)
{
	t_c		*nav;
	char	*name;
	int		i;

	name = NULL;
	i = 0;
	while (str[i] && str[i] != '=')
		name = ft_strjoin_char(name, str[i++]);
	nav = g_glob->envp;
	while (nav)
	{
		if (!ft_strncmp(name, nav->split[0], ft_strlen(nav->split[0]))
			&& ft_strlen(name))
		{
			if (str[i] == '=')
				curr_var_replacing(i, str, nav, name);
			return (1);
		}
		nav = nav->next;
	}
	if (name)
		free(name);
	return (0);
}

int	export_one(char *str)
{
	if (!str[0])
	{
		export_error("`'");
		return (1);
	}
	if (var_error(str))
		return (1);
	if (existing_var(str))
		return (0);
	add_envp(&g_glob->envp, str);
	return (0);
}

int	ft_export(char **tab)
{
	int	i;

	g_glob->code = 0;
	if (!tab[1])
		return (export_alone());
	i = 1;
	while (tab[i])
	{
		if (export_one(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
