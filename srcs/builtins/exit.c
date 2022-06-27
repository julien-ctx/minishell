/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:59 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/27 18:14:22 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_(char **argv)
{
	int	n;
	
	n = ft_atoi(argv[2]);
	if (argv[2])
		exit(n);
	exit (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	exit_(argv);
}
