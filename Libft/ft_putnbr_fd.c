/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:19:29 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:55:29 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	a;
	int		nb1;

	a = n;
	if (a < 0)
	{
		a = a * -1;
		write(fd, "-", 1);
	}
	if (a > 9)
		ft_putnbr_fd(a / 10, fd);
	nb1 = a % 10 + 48;
	write(fd, &nb1, 1);
}