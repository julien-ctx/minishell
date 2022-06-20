/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:55:44 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/20 19:24:54 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***************************************************************************
Oh it's you again ? You waited me to explain you how this export 🚀 works and 
what it is for ? 😂  Well, unfortunately i bas my ownes couilles ! But whatever
i'll still do it. Export can create a variable in the shell 🐢 if it doesn't 
exist.  However, it replaces the value by the new one you describe.
***************************************************************************/

#include "includes/minishell.h"

void export(char *str)
{
	t_list	*lst_env;
	char	*name;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	name = ft_strdup(str, 0, i);
	while 
	if (strncmp(str, name, i) == 0)	
				
	}
}