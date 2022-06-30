/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:26 by juliencauch       #+#    #+#             */
/*   Updated: 2022/06/29 11:31:38 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_quote(t_l *elmt)
{
	t_l	*nav;

	nav = elmt;
	while (nav->next != elmt)	
	{
		if (nav->type == D_QUOTE || nav->type == QUOTE)
			return (1);
		nav = nav->next;
	}
	if (nav->type == D_QUOTE || nav->type == QUOTE)
		return (1);
	return (0);
}
