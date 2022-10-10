/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:09:33 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 10:33:56 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/***************************************************************************
These functions are used to add a token, as an enum, on all the strings
inside each element of the linked list.
***************************************************************************/
int	is_builtin(char *str)
{
	if (builtin_syntax("echo", str))
		return (1);
	else if (builtin_syntax("cd", str))
		return (1);
	else if (builtin_syntax("pwd", str))
		return (1);
	else if (builtin_syntax("export", str))
		return (1);
	else if (builtin_syntax("unset", str))
		return (1);
	else if (builtin_syntax("env", str))
		return (1);
	else if (builtin_syntax("exit", str))
		return (1);
	return (0);
}

int	test_access(int i, char *curr, char **path, char *str)
{
	int	j;

	curr = strjoin_without_free(path[i], "/");
	curr = ft_strjoin(curr, str);
	if (!access(curr, F_OK))
	{
		j = 0;
		free(curr);
		while (path[j])
			free(path[j++]);
		free(path);
		return (1);
	}
	free(curr);
	return (0);
}

int	is_exec(char *str)
{
	char	**path;
	char	*all_paths;
	char	*curr_path;
	int		i;

	curr_path = NULL;
	all_paths = find_path("PATH");
	path = ft_split(all_paths, ':');
	free(all_paths);
	if (!path)
		return (0);
	i = -1;
	while (path[++i])
	{	
		if (test_access(i, curr_path, path, str))
			return (1);
		free(curr_path);
		curr_path = NULL;
	}
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return (0);
}

t_enum_type	chev_type(char *str)
{
	if (ft_strlen(str) == 1 && !ft_strncmp(str, "<", 1))
		return (L_CHEV);
	else if (ft_strlen(str) == 1 && !ft_strncmp(str, ">", 1))
		return (R_CHEV);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "<<", 2))
		return (L_DCHEV);
	return (R_DCHEV);
}

t_enum_type	find_type(char *str)
{
	if (is_builtin(str))
		return (BUILTIN);
	else if (is_exec(str))
		return (EXEC);
	else if (str[0] == '<' || str[0] == '>')
		return (chev_type(str));
	else if (str[0] == '|')
		return (PIPE);
	else if (str[0] == '\'')
		return (QUOTE);
	else if (str[0] == '"')
		return (D_QUOTE);
	else if (str[0] == ' ' || (str[0] >= 9 && str[0] <= 13))
		return (WHITE_SPACE);
	else
		return (TEXT);
	return (-1);
}
