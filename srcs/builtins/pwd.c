/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:02:34 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 19:55:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(char **tab)
{
	char	cwd[1024];

	if (!tab[1])
	{
		getcwd(cwd, 1024);
		printf("%s\n", cwd);
		g_glob->code = 0;
		return ;
	}
	if (tab[1][0] == '-')
	{
		getcwd(cwd, 1024);
		printf("minishell: pwd: options are not handled\n");
		g_glob->code = 1;
		return ;
	}
	getcwd(cwd, 1024);
	printf("%s\n", cwd);
	g_glob->code = 0;
}
