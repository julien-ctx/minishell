/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_elmt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:06:58 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/23 18:31:04 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_l	*create_new_elmt(char *str)
{
	t_l	*new;
	
	new = malloc(sizeof(t_l));
	new->str = str;
	new->type = find_type(str);
	new->next = NULL;
	return (new);
}

t_l	*add_elmt(t_l **elmt, char *str)
{
	t_l	*nav;
	
	if (!*elmt)
	{
		*elmt = create_new_elmt(str);
		(*elmt)->next = NULL;
		return (*elmt);
	}
	nav = *elmt;
	while (nav->next)
		nav = nav->next;
	nav->next = create_new_elmt(str);
	return (*elmt);
}
