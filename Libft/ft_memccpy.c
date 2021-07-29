/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:21:48 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:54:59 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*csrc;
	unsigned char		*cdst;

	i = 0;
	csrc = src;
	cdst = dst;
	if (csrc == NULL && cdst == NULL)
		return (dst);
	while (i < n && (unsigned char)c != csrc[i])
	{
		cdst[i] = csrc[i];
		i++;
	}
	if (csrc[i] == (unsigned char)c && i < n)
	{
		cdst[i] = (unsigned char)c;
		return (&cdst[i + 1]);
	}
	if (i < n)
		cdst[i] = '\0';
	return (NULL);
}
