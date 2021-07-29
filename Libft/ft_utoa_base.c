/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:26:54 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:57:02 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_nbr_len(unsigned long nbr, int blen)
{
	int		nbrlen;

	nbrlen = 0;
	while (nbr != 0)
	{
		nbr = nbr / blen;
		nbrlen++;
	}
	return (nbrlen);
}

char		*ft_utoa_base(unsigned long nbr, char *base)
{
	int		nbrlen;
	int		blen;
	char	*str;

	blen = ft_strlen(base);
	if (!nbr)
		return (ft_strdup("0"));
	nbrlen = ft_find_nbr_len(nbr, blen);
	str = malloc(nbrlen + 1);
	str[nbrlen--] = '\0';
	while (nbr != 0)
	{
		str[nbrlen] = base[nbr % blen];
		nbrlen--;
		nbr = nbr / blen;
	}
	return (str);
}
