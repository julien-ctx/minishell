/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:39:13 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/09 19:22:00 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ctrl_c(int sig)
{
	(void)sig;
	return ;
}

void	signal_init(void)
{
	signal(SIGINT, ctrl_c);
}

void	req_args(void)
{
	printf("Hello\n");
}

int	main()
{
	signal_init();
	req_args();
}
