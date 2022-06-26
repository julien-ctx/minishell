/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_elmt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:06:58 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/26 13:24:16 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_l	*create_new_elmt(char *str)
{
	t_l	*new;
	new = malloc(sizeof(t_l));
	new->str = ft_strdup(str);
	new->type = find_type(str);
	free(g_glob->curr);
	g_glob->curr = NULL;
	return (new);
}

t_l	*add_elmt(t_l **elmt, char *str)
{
	t_l	*head;
	t_l	*new;
	
	if (!*elmt)
	{
		*elmt = create_new_elmt(str);
		(*elmt)->next = *elmt;
		(*elmt)->prev = *elmt;
		return (*elmt);
	}
	new = create_new_elmt(str);
	if ((*elmt)->next == *elmt && (*elmt)->prev == *elmt)
	{
		new->next = *elmt;
		new->prev = *elmt;
		(*elmt)->next = new;
		(*elmt)->prev = new;
		return (*elmt);
	}
	head = *elmt;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	new->next = head;
	return (*elmt);
}
