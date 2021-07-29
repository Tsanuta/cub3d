/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:09:16 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:55:16 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char const	*csrc;
	unsigned char		*cdst;

	csrc = src;
	cdst = dst;
	if (csrc == NULL && cdst == NULL)
		return (dst);
	if (cdst < csrc)
		cdst = ft_memcpy(cdst, csrc, len);
	else
	{
		while (len)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (dst);
}
