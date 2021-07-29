/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:30:54 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:55:42 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	int		lens1;

	lens1 = 0;
	while (s1[lens1])
		lens1++;
	if (!(ptr = (char *)malloc(sizeof(char) * (lens1 + 1))))
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
}
