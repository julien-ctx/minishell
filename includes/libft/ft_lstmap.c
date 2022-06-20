/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:16:33 by juliencauch       #+#    #+#             */
/*   Updated: 2022/06/20 17:15:33 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_lst;
// 	t_list	*last;
// 	t_list	*elem;
// 	void	*content;

// 	new_lst = NULL;
// 	last = NULL;
// 	while (lst)
// 	{
// 		content = f(lst->content);
// 		elem = ft_lstnew(content);
// 		if (!elem)
// 		{
// 			if (new_lst)
// 				ft_lstclear(&new_lst, del);
// 			return (NULL);
// 		}
// 		if (last)
// 			last->next = elem;
// 		if (!new_lst)
// 			new_lst = elem;
// 		last = elem;
// 		lst = lst->next;
// 	}
// 	return (new_lst);
// }
