/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:15:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/29 09:03:15 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/***************************************************************************
Main function to parse arguments and make the right behaviour.
***************************************************************************/
int	parser(t_l *elmt)
{
	if (type_size(elmt) == 1)
		return (single_one(elmt));
		return (single_one(elmt));
}
