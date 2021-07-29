/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:17:29 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:55:50 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = 0;
	srclen = 0;
	while (dst[dstlen])
	{
		dstlen++;
		i++;
	}
	while (src[srclen])
		srclen++;
	if (size > dstlen)
	{
		while (*src && i < size - 1)
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = '\0';
		return (srclen + dstlen);
	}
	return (srclen + size);
}
