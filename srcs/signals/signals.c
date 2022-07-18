/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:37:16 by jcauchet          #+#    #+#             */
/*   Updated: 2022/07/18 17:41:43 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// les ctrl sont sence exit avec un code en particulier, a checker

#include "../../includes/minishell.h"

/***************************************************************************
Handles CTRL C and SIGINT signal
***************************************************************************/
void	ctrl_c(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

/***************************************************************************
Handles CTRL \ and SIGQUIT signal
***************************************************************************/
void	ctrl_bs(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
}
/***************************************************************************
Main function to give the right function to a specific signal
***************************************************************************/
void	signal_init(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_bs);
}
