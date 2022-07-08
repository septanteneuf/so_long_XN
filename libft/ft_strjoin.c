/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:07:53 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 15:44:24 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dst;	
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	dst = malloc(l1 + l2 + 1);
	if (!dst)
		return (NULL);
	while (i < l1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < (l1 + l2 + 1))
	{
		dst[i] = s2[i - l1];
		i++;
	}
	return (dst);
}
