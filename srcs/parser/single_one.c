/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:26:23 by juliencauch       #+#    #+#             */
/*   Updated: 2022/06/25 18:56:21 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	text_handler(t_l *elmt)
{
	if (elmt->str[0] == '&')
		printf("minishell: syntax error near unexpected token `&'\n");
	return (STOP);
}

int	single_one(t_l *elmt)
{
	if (elmt->type == TEXT)
		return (text_handler(elmt));
		return (text_handler(elmt));
}

