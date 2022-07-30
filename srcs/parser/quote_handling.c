/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:02:10 by juliencauch       #+#    #+#             */
/*   Updated: 2022/07/30 17:09:21 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_to_parsed(char *str, t_p **parsed, int type)
{
	// printf("strrr '%s', type = %d\n", str, type);
	t_p	*new;
	t_p	*head;
	
	if (!(*parsed)->str)
	{
		(*parsed)->next = *parsed;
		(*parsed)->prev = *parsed;
		(*parsed)->str = str;
		if (type)
			(*parsed)->type = type;
		else
			(*parsed)->type = TEXT;
		return ;
	}
	new = malloc(sizeof(t_p));
	if (type)
		new->type = type;
	else
		new->type = TEXT;
	new->str = str;
	if ((*parsed)->next == *parsed || (*parsed)->prev == *parsed)
	{
		new->next = *parsed;
		new->prev = *parsed;
		(*parsed)->next = new;
		(*parsed)->prev = new;
		return ;
	}
	head = *parsed;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	new->next = head;
}

void	d_quote_handling(t_l **nav, t_l *elmt, t_p **parsed)
{
	char	*str;

	str = NULL;
	if ((*nav)->next != elmt)
		*nav = (*nav)->next;
	//handle case only one quote here
	while ((*nav)->next != elmt && (*nav)->next->type != D_QUOTE)
	{
		str = strjoin_without_free(str, (*nav)->str);
		*nav = (*nav)->next;
	}
	if ((*nav)->next->type == D_QUOTE)
		(*nav)->next->type = WHITE_SPACE;
	str = strjoin_without_free(str, (*nav)->str);
	add_to_parsed(str, parsed, NO);
}

t_p	*quote_handling(t_l *elmt, t_p **parsed)
{
	t_l	*nav;

	nav = elmt;
	while (nav->next != elmt)
	{
		if (nav->type == D_QUOTE)
			d_quote_handling(&nav, elmt, parsed);
		else if (nav->type != WHITE_SPACE)
			add_to_parsed(nav->str, parsed, nav->type);
		nav = nav->next;
	}
	if (nav->type == D_QUOTE)
		d_quote_handling(&nav, elmt, parsed);
	else if (nav->type != WHITE_SPACE)
		add_to_parsed(nav->str, parsed, nav->type);
	print_list_p(*parsed, 1);
	exit(1);
	return (*parsed);
}
