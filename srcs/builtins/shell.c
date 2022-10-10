/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:53:07 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/29 14:36:41 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	envp_init(char **env)
{
	int	i;

	if (!env)
	{
		g_glob->envp = NULL;
		return ;
	}
	else if (!env[0])
	{
		g_glob->envp = NULL;
		return ;
	}
	i = -1;
	while (env[++i])
		add_envp(&g_glob->envp, env[i]);
}
