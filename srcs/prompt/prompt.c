/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:34:38 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/17 14:11:47 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



char	*create_prompt(void)
{
	char	*prompt;
	char	cwd[1024];

	prompt = ft_strdup("\033[36;1m");
	prompt = ft_strjoin(prompt, getenv("USER"));
	prompt = ft_strjoin(prompt, "@:");
	prompt = ft_strjoin(prompt, "\033[31;1m");
	prompt = ft_strjoin(prompt, getcwd(cwd, sizeof(cwd)));
	prompt = ft_strjoin(prompt, "$ \033[0m");
	return (prompt);
}
