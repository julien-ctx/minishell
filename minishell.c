/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:39:13 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/10 17:44:32 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_global = 0;

void	req_args(void)
{
	char	*args;

	while (1)
	{
		args = print_prompt();
		if (g_global)
		{
			printf("\n");
			continue;
		}
		add_history(args);
		parsing(args);
	}
}

int	main()
{
	signal_init();
	req_args();
	system("leaks minishell");
}
