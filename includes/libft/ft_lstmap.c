/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:16:33 by juliencauch       #+#    #+#             */
/*   Updated: 2022/06/08 18:24:44 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*last;
	t_list	*elem;
	void	*content;

	new_lst = NULL;
	last = NULL;
	while (lst)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			if (new_lst)
				ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (last)
			last->next = elem;
		if (!new_lst)
			new_lst = elem;
		last = elem;
		lst = lst->next;
	}
	return (new_lst);
}
