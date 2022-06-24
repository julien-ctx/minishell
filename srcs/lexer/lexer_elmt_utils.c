/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_elmt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:06:58 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/24 14:14:14 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_l	*create_new_elmt(char *str)
{
	t_l	*new;
	
	new = malloc(sizeof(t_l));
	new->str = str;
	new->type = find_type(str);
	return (new);
}

t_l	*add_elmt(t_l **elmt, char *str)
{
	t_l	*tmp;
	t_l	*new;
	
	if (!*elmt)
	{
		*elmt = create_new_elmt(str);
		(*elmt)->next = *elmt;
		(*elmt)->prev = *elmt;
		return (*elmt);
	}
	new = create_new_elmt(str);
	new->next = *elmt;
	tmp = (*elmt)->prev;
	tmp->next = new;
	new->prev = tmp;
	(*elmt)->prev = new;
	return (*elmt);
}
