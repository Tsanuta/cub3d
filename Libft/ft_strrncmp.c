/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:50:47 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:56:45 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		salen;
	int		sblen;

	i = 0;
	if (n == 0)
		return (0);
	salen = ft_strlen(s1) - 1;
	sblen = ft_strlen(s2) - 1;
	while (salen > -1 && sblen > -1 && i < n)
	{
		if (s1[salen] != s2[sblen])
			return ((unsigned char)s1[salen] - (unsigned char)s2[sblen]);
		salen--;
		sblen--;
		i++;
	}
	return ((unsigned char)s1[salen] - (unsigned char)s2[sblen]);
}
