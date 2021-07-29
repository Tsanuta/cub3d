/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_rayx_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 11:26:04 by olidon            #+#    #+#             */
/*   Updated: 2020/02/16 17:58:17 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	ft_find_rayx_ay(float ra, t_elem *e, int prec)
{
	if (ra == 0 || ra == M_PI)
		return (e->p.y);
	if (ra > 0 && ra < M_PI)
		return (trunc(e->p.y / prec) * prec - 0.001);
	else
		return (trunc(e->p.y / prec) * prec + prec);
}

float	ft_find_rayx_ya(float ra, int prec)
{
	if (ra == 0 || ra == M_PI)
		return (0);
	if (ra > 0 && ra < M_PI)
		return (-prec);
	else
		return (prec);
}

float	ft_find_rayx_ax(float ra, float ay, t_elem *e)
{
	if (ra == 0 || ra == M_PI || ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (e->p.x);
	else
		return (e->p.x + (e->p.y - ay) / tan(ra));
}

float	ft_find_rayx_xa(float ra, int prec)
{
	if (ra == 0 || ra == M_PI)
	{
		if (ra == M_PI)
			return (-prec);
		return (prec);
	}
	else if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (0);
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
		return (-prec / fabs(tan(ra)));
	else
		return (prec / fabs(tan(ra)));
}
