/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:34:38 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/11 17:36:36 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_prompt(void)
{
	char	cwd[1024];

	printf("\e[1;36m");
	printf("%s@:", getenv("USER"));
	printf("\e[1;31m");
	printf("%s$ ", getcwd(cwd, sizeof(cwd)));
	printf("\033[0m");
}
