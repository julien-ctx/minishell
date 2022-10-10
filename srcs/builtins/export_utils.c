/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:54:46 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 14:04:56 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export_alone(void)
{
	print_export();
	g_glob->code = 0;
	return (0);
}

int	export_error(char *str)
{
	printf("minishell: export: %s: not a valid identifier\n", str);
	g_glob->code = 1;
	return (1);
}

int	var_error(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '=')
		return (export_error(str));
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
			return (export_error(str));
		i++;
	}
	return (0);
}

void	replace_curr_path(int i, char *str, t_c **nav)
{
	char	*path;

	path = NULL;
	if (!str[i + 1])
	{
		if ((*nav)->split[1])
			free((*nav)->split[1]);
		(*nav)->split[1] = ft_strdup("");
		return ;
	}
	i++;
	while (str[i])
	{
		path = ft_strjoin_char(path, str[i]);
		i++;
	}
	if ((*nav)->split[1])
		free((*nav)->split[1]);
	(*nav)->split[1] = path;
}
