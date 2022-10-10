/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:39:02 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 13:39:13 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	return_not_set(char *new)
{
	printf("minishell: cd: HOME not set\n");
	if (new)
		free(new);
	g_glob->code = 1;
	return (1);
}
