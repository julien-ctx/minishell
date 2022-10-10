/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:27:45 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 19:56:05 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_syntax(char *ref, char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(ref) != ft_strlen(str))
		return (0);
	if (!ref || !str)
		return (0);
	while (ref[i])
	{
		if ((str[i] == ref[i]) || (str[i] == ref[i] - 32))
			i++;
		else
			return (0);
	}
	return (1);
}
