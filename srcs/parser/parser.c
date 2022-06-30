/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:15:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/30 10:57:19 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/***************************************************************************
Main function to parse arguments and make the right behaviour.
***************************************************************************/
int	parser(t_l *elmt)
{
	t_p	*parsed;
	
	if (is_quote(elmt))
		quote_handling(elmt, &parsed);
	/*if (is_pipe(elmt))
		check_pipe_syntax(elmt);*/
	return(1);
}
