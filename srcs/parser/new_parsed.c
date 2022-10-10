/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:00:28 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/28 13:08:46 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_tab_len(t_p *parsed)
{
	int	i;
	int	count;
	t_p	*nav;

	i = 0;
	count = 0;
	nav = parsed;
	while (nav)
	{
		if (nav->type != WHITE_SPACE && !i)
		{
			count++;
			i = 1;
		}
		else if (nav->type == WHITE_SPACE)
			i = 0;
		nav = nav->next;
	}
	return (count);
}

void	create_all_tabs(t_p *nav, char *str, int *index, char **tab)
{
	while (nav)
	{
		if (nav->type != WHITE_SPACE && !index[0])
		{
			str = ft_strdup(nav->str);
			index[0] = 1;
		}
		else if (nav->type != WHITE_SPACE && index[0])
			str = ft_strjoin(str, nav->str);
		else if (nav->type == WHITE_SPACE && index[0])
		{
			tab[index[1]++] = str;
			str = NULL;
			index[0] = 0;
		}
		nav = nav->next;
	}
	if (str)
	{
		tab[index[1]++] = str;
		str = NULL;
	}
	tab[index[1]] = NULL;
}

char	**args_tab(t_p *parsed, char **tab)
{
	t_p		*nav;
	int		boolean;
	char	*str;
	int		i;

	boolean = 0;
	i = 0;
	nav = parsed;
	str = NULL;
	create_all_tabs(nav, str, (int [2]){boolean, i}, tab);
	return (tab);
}

char	**recreate_parsed(t_p *parsed)
{
	char	**tab;
	int		len;

	change_t_p(&parsed, 1);
	len = find_tab_len(parsed);
	tab = malloc(sizeof(char *) * (len + 1));
	tab = args_tab(parsed, tab);
	change_t_p(&parsed, 0);
	return (tab);
}
