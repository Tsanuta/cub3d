/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:59:28 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:54:20 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_checknsize(long a)
{
	unsigned int nsize;

	nsize = 0;
	if (a < 0)
		nsize++;
	while (a > 9 || a < -9)
	{
		a = a / 10;
		nsize++;
	}
	return (nsize);
}

static char			*ft_fillstr(char *str, long a, unsigned int nsize)
{
	while (a > 9)
	{
		str[nsize] = a % 10 + 48;
		a = a / 10;
		nsize--;
	}
	str[nsize] = a % 10 + 48;
	return (str);
}

char				*ft_itoa(int n)
{
	long			a;
	char			*str;
	unsigned int	nsize;

	a = n;
	nsize = ft_checknsize(a);
	if (!(str = (char *)malloc(sizeof(char) * (nsize + 2))))
		return (NULL);
	if (a < 0)
	{
		a = a * -1;
		str[0] = '-';
	}
	str[nsize + 1] = '\0';
	str = ft_fillstr(str, a, nsize);
	return (str);
}
