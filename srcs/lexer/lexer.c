/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:50 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/22 16:13:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	checker_type(char *args, t_l **elmt, int i)
{
	if (args[i] == '\0')
	{
		if (g_glob->curr)
		{
			add_elmt(elmt, g_glob->curr);	
			g_glob->curr = NULL;
		}
	}
	else if (ft_isalnum(args[i]))
		g_glob->curr = append_char(g_glob->curr, args[i]);
}

void	lexer(char *args)
{
	int		i;
	t_l		*elmt;

	elmt = NULL;
	g_glob->curr = NULL;
	i = -1;
	while (args[++i])
		checker_type(args, &elmt, i);
	checker_type(args, &elmt, i);
	if (!elmt)
	{
			printf("kebab\n");
	}
	while (elmt)
	{
		printf("'%s', '%d'\n", elmt->str, elmt->type);
		elmt = elmt->next;
	}
}
