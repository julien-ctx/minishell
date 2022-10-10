/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:12:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 18:15:03 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **tab)
{
	g_glob->code = 0;
	if (!tab[1])
		print_env();
	else
	{
		printf("minishell: env: options and arguments are not handled\n");
		g_glob->code = 1;
	}
}
