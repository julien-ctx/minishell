/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:15:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/07/28 11:06:50 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/***************************************************************************
Main function to parse arguments and make the right behaviour.
***************************************************************************/
int	parser(t_l *elmt)
{
	t_p	*parsed;
	
	parsed = malloc(sizeof(t_p));
	parsed->str = NULL;
	quote_handling(elmt, &parsed);
	/*if (is_pipe(elmt))
		check_pipe_syntax(elmt);*/
	return(1);
}
