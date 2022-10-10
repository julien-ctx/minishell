/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:03:01 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/26 23:04:09 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_path(char *str)
{
	t_c	*nav;

	nav = g_glob->envp;
	while (nav)
	{
		if (!ft_strncmp(str, nav->split[0], 4) && ft_strlen(nav->split[0]) == 4)
			return (ft_strdup(nav->split[1]));
		nav = nav->next;
	}
	return (NULL);
}
