/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:57:27 by juliencauch       #+#    #+#             */
/*   Updated: 2021/10/20 11:58:56 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*string;

	len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	i = 0;
	j = 0;
	string = malloc(len * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[j])
		string[i++] = (char)s1[j++];
	j = 0;
	while (s2[j])
		string[i++] = (char)s2[j++];
	string[i] = '\0';
	return (string);
}
