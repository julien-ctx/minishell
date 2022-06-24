/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:02:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/24 19:18:34 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_path(char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*string;
	char	c;

	c = '"';
	i = 0;
	j = 0;
	len = ft_strlen(s2) + 3;
	string = malloc(len * sizeof(char));
	if (!string)
		return (NULL);
	string[i++] = c;
	while (s2[j])
		string[i++] = s2[j++];
	string[i++] = c;
	string[i] = '\0';
	return (string);
}

int	is_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] >= 65 && str[i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122))
			i++;
		if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
			return (1);
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] >= 48 && str[i] <= 57))
			i++;
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
	}
	return (0);
}

char	*name_checker(char *str)
{
	int		i;
	char	*clean_name;

	i = 0;
	while ((is_letter(str) && is_number(str)) || str[i] == '_')
	{
		i++;
		if (str[i] == '+')
		{
			i++;
			if (str[i] == '=')
			{
				clean_name = ft_substr(str, 0, (i - 2));
				return (clean_name);
			}
			printf("On a une erreur dans le name Jacson\n");
			exit (0);
		}
		return (str);
	}
	printf("On a une erreur dans le name Jacson\n");
	exit (0);
}

t_list	*ft_lstnew(char *env_choosen, int size)
{
	t_list	*lst;
	int		size_env;
	char	*raw_name;

	size_env = ft_strlen(env_choosen);
	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->head = ft_strdup("declare -x ");
	raw_name = ft_substr(env_choosen, 0, size);
	lst->name = name_checker(raw_name);
	lst->linker = '=';
	lst->path = make_path(ft_substr(env_choosen, size + 1, size_env));
	lst->next = NULL;
	lst->next_sort = NULL;
	return (lst);
}
