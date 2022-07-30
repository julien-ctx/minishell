/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:02:10 by juliencauch       #+#    #+#             */
/*   Updated: 2022/07/30 11:42:42 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	str = strjoin_without_free(str, (*nav)->str);
	printf("Final str : %s\n", str);
	(void)parsed;
	exit(1);
}

t_p	*quote_handling(t_l *elmt, t_p **parsed)
{
	t_l	*nav;

	nav = elmt;
	while (nav->next != elmt)
	{
		if (nav->type == D_QUOTE)
			d_quote_handling(&nav, elmt, parsed);
		/*else
			add_to_parsed(nav, elmt, parsed);*/
		nav = nav->next;
	}
	return (*parsed);
}
