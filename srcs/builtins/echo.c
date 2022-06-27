/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:58:20 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/27 15:35:47 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	checker_flag(int argc, char **argv)
{
	(void)argc;
	if (strncmp(argv[1], "-n", 2) == 0)
		return (2);
	return (1);
}

void	echo(int argc, char **argv)
{
	char	*echo;
	int		i;
	int		end;

	i = checker_flag(argc, argv);	
	end = i;
	while (i < argc)
	{	
		if (i == argc - 1)
		{
			echo = ft_strdup(argv[i++]);
			if (end == 2)
			{
				printf("%s", echo);
				exit (0);		
			}
			printf("%s\n", echo);
			exit (0);		
		}
		echo = ft_strdup(argv[i++]);
		printf("%s ", echo);
	}
}

// int main(int argc, char **argv)
// {
// 	checker_flag(argc, argv);
// 	echo(argc, argv);
// }
