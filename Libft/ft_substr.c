/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:01:34 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:56:52 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strfill(char const *s, unsigned int start,
												size_t len, char *str)
{
	size_t	i;

	i = 0;
	if (start <= ft_strlen(s))
	{
		while (s[i + start] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || !len || start >= ft_strlen(s))
		return (ft_strdup(""));
	else if ((start + len) > ft_strlen(s))
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1))))
			return (NULL);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
	}
	str = ft_strfill(s, start, len, str);
	return (str);
}
