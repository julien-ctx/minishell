/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:02:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/06/20 18:16:44 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *env_choosen, int size)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->name = ft_substr(env_choosen, 0, size);
	lst->path = ft_substr(env_choosen, size + 1, ft_strlen(env_choosen));
	lst->next = NULL;
	return (lst);
}
