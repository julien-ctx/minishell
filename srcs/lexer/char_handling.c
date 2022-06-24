/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:12:45 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/24 15:34:33 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_quote(char *args, t_l **elmt, int *i)
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

void	handle_pipe(char *args, t_l **elmt, int *i)
{
	if (g_glob->curr)
	{
		add_elmt(elmt, g_glob->curr);	
		g_glob->curr = NULL;	
	}
	while (args[*i] == '|')
	{
		g_glob->curr = append_char(g_glob->curr, args[*i]);
		(*i)++;
	}
	add_elmt(elmt, g_glob->curr);	
	g_glob->curr = NULL;	
	(*i)--;	
}

void	handle_w_s(char *args, t_l **elmt, int *i)
{
	if (g_glob->curr)
	{
		add_elmt(elmt, g_glob->curr);	
		g_glob->curr = NULL;	
	}
	while ((args[*i] == ' ') || (args[*i] >= 9 && args[*i] <= 13))
	{
		g_glob->curr = append_char(g_glob->curr, args[*i]);
		(*i)++;
	}
	add_elmt(elmt, g_glob->curr);	
	g_glob->curr = NULL;	
	(*i)--;
}

void	handle_dollar(char *args, t_l **elmt, int *i)
{
	g_glob->curr = append_char(g_glob->curr, args[*i]);
	add_elmt(elmt, g_glob->curr);
	g_glob->curr = NULL;
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
