/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:15:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/07/31 18:31:26 by jcauchet         ###   ########.fr       */
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
	return(1);
}
