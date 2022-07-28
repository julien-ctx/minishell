/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:02:10 by juliencauch       #+#    #+#             */
/*   Updated: 2022/07/28 15:09:59 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_d_quote(t_l *nav, t_p **parsed)
{
	t_l	*next;
	
	nav = nav->next;
	while (nav->next != )
	{
		if (nav->type == D_QUOTE)
		{
			next = nav;
			while (next->type != D_QUOTE)
			{
				
			}
		}
		else
		{
			
		}
		nav = nav->next;
	}	
}

void	add_to_parsed(t_l *nav, t_p **parsed, int find_type)
{
	t_p	*new;
	t_p	*head;
	
	if (!(*parsed)->str)
	{
		(*parsed)->str = nav->str;
		(*parsed)->next = *parsed;
		(*parsed)->prev = *parsed;
	}
	else if ((*parsed)->next == *parsed || (*parsed)->prev == *parsed)
	{
		new = malloc(sizeof(t_p));
		new->next = *parsed;
		new->prev = *parsed;
		(*parsed)->next = new;
		(*parsed)->prev = new->prev;
	}
	else
	{
		new = malloc(sizeof(t_p));
		head = *parsed;
		new->prev = head->prev;
		head->prev->next = new;
		head->prev = new;
		new->next = *parsed;
	}
	if (find_type == YES)
	{

	}
	else
	{
		
	}
}


t_p	*quote_handling(t_l *elmt, t_p **parsed)
{
	t_l	*nav;

	nav = elmt;
	while (nav->next != elmt)
	{
		if (nav->type == D_QUOTE)
			check_d_quote(nav, parsed);
		else
			add_to_parsed(nav, parsed, NO);
		nav = nav->next;
		
	}
}
