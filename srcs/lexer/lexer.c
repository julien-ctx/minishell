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

/***************************************************************************
This function checks input characters, one by one, and creates tokens to
separate in different part the input string. After that, the parser will
see if the newly created token string make sense or is bullshit.
***************************************************************************/
void	checker_type(char *args, t_l **elmt, int *i)
{
	if (args[*i] == '\0')
		end_handler(elmt);
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
	else if (args[*i] == '.')
		general_handler(args, elmt, i, DOT);
	else if (args[*i] == '/')
		general_handler(args, elmt, i, SLASH);
	else if (args[*i] == '-')
		general_handler(args, elmt, i, DASH);
	else
		g_glob->curr = append_char(g_glob->curr, args[*i]);
}

int	lexer(char *args)
{
	int		i;
	t_l		*elmt;
	t_l		*nav;

	elmt = NULL;
	g_glob->curr = NULL;
	i = -1;
	while (args[++i])
		checker_type(args, &elmt, &i);
	checker_type(args, &elmt, &i);
	//still neeed to check leaks here in case 
	//parser returns STOP
	print_list_j(elmt, 1);
	if (parser(elmt) == STOP)
	{
		nav = elmt;
		free(args);
		while (nav->next != elmt)
		{
			nav = nav->next;
			free(nav->prev->str);
			free(nav->prev);
		}
		free(nav->str);
		free(nav);
		return(STOP);
	}
	return (CONTINUE);
}
