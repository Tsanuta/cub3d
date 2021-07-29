/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:30:51 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:53:44 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int nbr, int power)
{
	int	newnbr;

	newnbr = nbr;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		newnbr = newnbr * nbr;
		power--;
	}
	return (newnbr);
}

static int		ft_posbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

unsigned int	ft_atou_base(char *str, char *base)
{
	unsigned int	nbr;
	int				blen;
	int				sign;
	int				slen;
	int				i;

	i = 0;
	sign = 1;
	slen = ft_strlen(str);
	blen = ft_strlen(base);
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < slen)
	{
		nbr = nbr + ft_posbase(str[i], base) * ft_power(blen, (slen - i - 1));
		i++;
	}
	return (nbr * sign);
}
