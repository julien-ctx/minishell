/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:28:18 by juliencauch       #+#    #+#             */
/*   Updated: 2022/06/25 18:30:12 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	type_size(t_l *elmt)
{
	t_l	*nav;
	int	i;

	i = 0;
	nav = elmt;
	while (nav->next != elmt)
	{
		i++;
		nav = nav->next;
	}
	i++;
	return (i);
}
