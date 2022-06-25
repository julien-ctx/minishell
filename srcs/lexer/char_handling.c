/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:12:45 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/25 17:13:05 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_quotes(char *args, t_l **elmt, int *i)
{
	if (g_glob->curr)
	{
		add_elmt(elmt, g_glob->curr);	
		g_glob->curr = NULL;	
	}
	g_glob->curr = append_char(g_glob->curr, args[*i]);
	add_elmt(elmt, g_glob->curr);
	g_glob->curr = NULL;
}

void	check_successive(char *args, int *i, int type)
{
	if (type == WHITE_SPACE)
		while ((args[*i] == ' ') || (args[*i] >= 9 && args[*i] <= 13))
			g_glob->curr = append_char(g_glob->curr, args[(*i)++]);
	else if (type == DOLLAR)
		while (args[*i] == '$')
			g_glob->curr = append_char(g_glob->curr, args[(*i)++]);	
	else if (type == PIPE)
		while (args[*i] == '|')
			g_glob->curr = append_char(g_glob->curr, args[(*i)++]);	
	else if (type == BACK_SLASH)
		while (args[*i] == '\\')
			g_glob->curr = append_char(g_glob->curr, args[(*i)++]);	
}

void	general_handler(char *args, t_l **elmt, int *i, int type)
{
	if (g_glob->curr)
	{
		add_elmt(elmt, g_glob->curr);	
		g_glob->curr = NULL;	
	}
	check_successive(args, i, type);
	add_elmt(elmt, g_glob->curr);	
	g_glob->curr = NULL;	
	(*i)--;
}

void	handle_chev(char *args, t_l **elmt, int *i)
{
	if (g_glob->curr)
	{
		add_elmt(elmt, g_glob->curr);	
		g_glob->curr = NULL;
	}
	g_glob->curr = append_char(g_glob->curr, args[*i]);
	if (args[*i + 1] == args[*i])
	{
		g_glob->curr = append_char(g_glob->curr, args[*i + 1]);
		add_elmt(elmt, g_glob->curr);
		g_glob->curr = NULL;
		(*i)++;
	}
	else
	{
		add_elmt(elmt, g_glob->curr);
		g_glob->curr = NULL;
	}
}
