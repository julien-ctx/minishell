/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:29:37 by juliencauch       #+#    #+#             */
/*   Updated: 2022/06/29 10:00:28 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_pipe(t_l *elmt)
{
	t_l		*nav;

	nav = elmt;
	while (nav->next != elmt)
	{
		if (nav->type == PIPE)
		nav = nav->next;
	}
	if (nav->type == PIPE)
		return (1);
	return (0);	
}
