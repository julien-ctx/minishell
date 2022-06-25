/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_elmt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:06:58 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/25 22:31:03 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int z = 0;
t_l	*create_new_elmt(char *str)
{
	z++;
	t_l	*new;
	new = malloc(sizeof(t_l));
	new->str = str;
	printf("z vaut %d et str %s'\n", z,str);
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
