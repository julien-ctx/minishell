/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:07:02 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/07 21:35:49 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*home_path(void)
{
	t_c	*nav;

	nav = g_glob->envp;
	while (nav)
	{
		if (nav->split)
		{
			if (ft_strlen(nav->split[0]) == 4
				&& !ft_strncmp(nav->split[0], "HOME", 4))
			{
				if (nav->split[1])
					return (nav->split[1]);
				else
					return (NULL);
			}
		}
		nav = nav->next;
	}
	return (NULL);
}

int	cd_alone(void)
{
	char	*path;

	path = home_path();
	if (!path)
	{
		printf("minishell: cd: HOME not set\n");
		g_glob->code = 1;
		return (1);
	}
	chdir(path);
	return (0);
}

int	check_options_cd(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		if (str[i] == '-' && str[i + 1])
		{
			printf("minishell: cd: options are not handled\n");
			g_glob->code = 1;
			return (1);
		}
	}
	return (0);
}

int	tilde_handling(char **tab)
{
	int		i;
	char	*new;
	char	*home;

	new = NULL;
	i = -1;
	while (tab[1][++i])
	{
		if (tab[1][i] == '~')
		{
			home = home_path();
			if (!home)
				return (return_not_set(new));
			if (!home[0])
				return (return_not_set(new));
			new = ft_strjoin(new, home_path());
		}
		else
			new = ft_strjoin_char(new, tab[1][i]);
	}
	free(tab[1]);
	tab[1] = new;
	return (0);
}

int	ft_cd(char **tab)
{
	int		ret;

	g_glob->code = 0;
	if (!tab[1])
		return (cd_alone());
	if (check_options_cd(tab[1]))
		return (1);
	if (tilde_handling(tab))
		return (1);
	ret = chdir(tab[1]);
	if (ret == -1)
	{
		printf("minishell: cd: %s: no such file or directory\n", tab[1]);
		g_glob->code = 1;
	}
	return (0);
}
