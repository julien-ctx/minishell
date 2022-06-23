/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:29:32 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/23 17:38:59 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *str)
{
	if (ft_strlen(str) == 4 && !ft_strncmp(str, "echo", 4))
		return (1);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "cd", 2))
		return (1);
	else if (ft_strlen(str) == 3 && !ft_strncmp(str, "pwd", 3))
		return (1);
	else if (ft_strlen(str) == 6 && !ft_strncmp(str, "export", 6))
		return (1);
	else if (ft_strlen(str) == 5 && !ft_strncmp(str, "unset", 5))
		return (1);
	else if (ft_strlen(str) == 3 && !ft_strncmp(str, "env", 3))
		return (1);
	else if (ft_strlen(str) == 4 && !ft_strncmp(str, "exit", 4))
		return (1);
	return (0);
}

int	is_exec(char *str)
{
	char	**path;
	char	*all_paths;
	char	*curr_path;
	int		i;
	
	all_paths = getenv("PATH");
	path = ft_split(all_paths, ':');
	i = 0;
	while (path[i])
	{
		curr_path = ft_strjoin(path[i], "/");	
		curr_path = ft_strjoin(curr_path, str);	
		if (!access(curr_path, F_OK))
		{
			free(curr_path);
			return (1);
		}
		free(curr_path);
		i++;
	}
	free(path);
	return (0);
}

t_enum_l	chev_type(char *str)
{
	if (ft_strlen(str) == 1 && !ft_strncmp(str, "<", 1))
		return (L_CHEV);
	else if (ft_strlen(str) == 1 && !ft_strncmp(str, ">", 1))
		return (R_CHEV);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "<<", 2))
		return (L_DCHEV);
	return (R_DCHEV);
}

t_enum_l find_type(char *str)
{
	/*if (!str[0])
		printf("NULL\n");*/
	if (is_builtin(str))
		return (BUILTIN);
	else if (is_exec(str))
		return (EXEC);
	else if (str[0] == '<' || str[0] == '>')
		return (chev_type(str));
	else if (!ft_strncmp("|", str, 1) && ft_strlen(str) == 1)
		return (PIPE);
	return (-1);
}
