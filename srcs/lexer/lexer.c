/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:58:50 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/21 18:39:27 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_enum_pl	type(char c)
{
	if (c == "$")
		return (PIPE);
	
}

void	lexer(char *args)
{
	int		i;
	int		len;
	t_pl	*str;
	
	len = ft_strlen(args);
	i = 0;
	str = malloc(sizeof(len + 1));
	while (i < len)
	{
		str->c = str[i++];
		str->type = check_type(str[i]);
		i++;
	}
}
