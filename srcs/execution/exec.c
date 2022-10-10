/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:18:30 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 14:09:33 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**generate_envp(void)
{
	t_c		*nav;
	char	**tab;
	int		i;

	i = 0;
	nav = g_glob->envp;
	while (nav)
	{
		i++;
		nav = nav->next;
	}
	tab = malloc(sizeof(char *) * (i + 1));
	i = 0;
	nav = g_glob->envp;
	while (nav)
	{
		tab[i] = ft_strdup(nav->split[0]);
		tab[i] = ft_strjoin(tab[i], "=");
		if (nav->split[1])
			tab[i] = ft_strjoin(tab[i], nav->split[1]);
		i++;
		nav = nav->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	*find_correct_path(char *str, char *path)
{
	char	**all_paths;
	char	*tmp;
	int		i;

	if (!path)
		return (NULL);
	all_paths = ft_split(path, ':');
	i = 0;
	while (all_paths[i])
	{
		tmp = NULL;
		tmp = strjoin_without_free(all_paths[i], "/");
		tmp = ft_strjoin(tmp, str);
		if (!access(tmp, F_OK))
		{
			free_tab(all_paths);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free_tab(all_paths);
	return (NULL);
}

char	*find_path_var(char *str)
{
	t_c	*nav;

	nav = g_glob->envp;
	if (!nav)
		return (NULL);
	while (nav)
	{
		if (ft_strlen(nav->split[0]) == 4
			&& !ft_strncmp(nav->split[0], "PATH", 4))
			return (find_correct_path(str, nav->split[1]));
		nav = nav->next;
	}
	return (NULL);
}

void	child_exec(char **tab)
{
	char	**new;
	char	*path;

	new = generate_envp();
	path = find_path_var(tab[0]);
	if (!path)
	{
		printf("minishell: %s: no such file or directory\n", tab[0]);
		g_glob->code = 127;
		exit(127);
	}
	execve(path, tab, new);
	free(path);
	free_tab(new);
	exit(3);
}

void	find_command(char **tab)
{
	int	status;
	int	id;

	id = fork();
	if (id == -1)
		perror("Error");
	else if (id)
		g_glob->code = 137 + SIGKILL;
	else
		child_exec(tab);
	waitpid(0, &status, 0);
	g_glob->code = exit_code(status);
}
