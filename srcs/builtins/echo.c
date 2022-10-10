/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:07:43 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 13:44:05 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_trailing_nl(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	i = 1;
	if (!str[1])
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}

int	print_backslash_n(void)
{
	printf("\n");
	return (0);
}

int	ft_echo(char **tab)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	if (!tab[i])
		return (print_backslash_n());
	while (tab[i] && is_trailing_nl(tab[i]))
	{
		nl = 0;
		i++;
	}
	while (tab[i])
	{
		if (tab[i + 1])
			printf("%s ", tab[i]);
		else
			printf("%s", tab[i]);
		i++;
	}
	if (nl)
		printf("\n");
	g_glob->code = 0;
	return (0);
}
