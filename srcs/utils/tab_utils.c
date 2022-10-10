/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:15:00 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 10:19:09 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	tab_only_spaces(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		if ((tab[i] != ' ') || (tab[i] < 9) || (tab[i] > 13))
			return (0);
	return (1);
}
