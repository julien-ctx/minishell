/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:50 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/25 16:58:40y juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_list_j(t_l *elmt, int n)
{
	t_l *tmp;

	if (n)
	{
		tmp = elmt;
		while (tmp->next != elmt)
		{
			printf("str='%s', type='%d'\n", tmp->str, tmp->type);
			tmp = tmp->next;
		}
		printf("str='%s', type='%d'\n", tmp->str, tmp->type);
	}
	else
	{
		tmp = elmt->prev;
		while (tmp->prev != elmt->prev)
		{
			printf("str='%s', type='%d'\n", tmp->str, tmp->type);
			tmp = tmp->prev;
		}
		printf("str='%s', type='%d'\n", tmp->str, tmp->type);
	}
}

void	checker_type(char *args, t_l **elmt, int *i)
{
	if (args[*i] == '\0')
	{
		if (g_glob->curr)
		{
			add_elmt(elmt, g_glob->curr);	
			g_glob->curr = NULL;
		}
	}
	else if ((args[*i] == ' ') || (args[*i] >= 9 && args[*i] <= 13))
		general_handler(args, elmt, i, WHITE_SPACE);
	else if (args[*i] == '<' || args[*i] == '>')
		handle_chev(args, elmt, i);
	else if (args[*i] == '$')
		general_handler(args, elmt, i, DOLLAR);
	else if (args[*i] == '|')
		general_handler(args, elmt, i, PIPE);
	else if (args[*i] == '"' || args[*i] == '\'')
		handle_quotes(args, elmt, i);
	else if (args[*i] == '\\')
		general_handler(args, elmt, i, BACK_SLASH);
	else
		g_glob->curr = append_char(g_glob->curr, args[*i]);
	/*else if (ft_isalnum(args[*i]))
	g_glob->curr = append_char(g_glob->curr, args[*i]);*/
}

void	lexer(char *args)
{
	int		i;
	t_l		*elmt;

	elmt = NULL;
	g_glob->curr = NULL;
	i = -1;
	while (args[++i])
		checker_type(args, &elmt, &i);
	checker_type(args, &elmt, &i);
	print_list_j(elmt, 1);
}
