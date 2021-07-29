/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_rayy_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 11:33:59 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:47:23 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

float	ft_find_rayy_ax(float ra, t_elem *e, int prec)
{
	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (e->p.x);
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
		return (trunc(e->p.x / prec) * prec - 0.001);
	else
		return (trunc(e->p.x / prec) * prec + prec);
}

float	ft_find_rayy_xa(float ra, int prec)
{
	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (0);
	if (ra >= M_PI / 2 && ra <= 3 * M_PI / 2)
		return (-prec);
	else
		return (prec);
}

float	ft_find_rayy_ay(float ra, float ax, t_elem *e)
{
	if (ra == 0 || ra == M_PI || ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (e->p.y);
	else
		return (e->p.y + (e->p.x - ax) * tan(ra));
}

float	ft_find_rayy_ya(float ra, int prec)
{
	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
	{
		if (ra == M_PI / 2)
			return (-prec);
		return (prec);
	}
	else if (ra == 0 || ra == M_PI)
		return (0);
	if (ra > 0 && ra < M_PI)
		return (-prec * fabs(tan(ra)));
	else
		return (prec * fabs(tan(ra)));
}
