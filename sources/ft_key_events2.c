/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:10:01 by olidon            #+#    #+#             */
/*   Updated: 2020/02/24 12:48:20 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_exit_windows(t_elem *e)
{
	ft_free_struct_elem(e);
	return (0);
}

static void	ft_increment_pangle(t_elem *e, float inc)
{
	e->p.a += inc;
	if (e->p.a >= 2 * M_PI)
		e->p.a = e->p.a - 2 * M_PI;
	if (e->p.a < 0)
		e->p.a = e->p.a + 2 * M_PI;
}

static void	ft_fill_comp(t_elem *e, float *xcomp, float *ycomp)
{
	*xcomp = e->mvmnt.w * cos(e->p.a) + e->mvmnt.a *
	cos(e->p.a + M_PI / 2) + e->mvmnt.s * cos(e->p.a + M_PI) + e->mvmnt.d *
	cos(e->p.a + 3 * M_PI / 2);
	*ycomp = e->mvmnt.w * sin(e->p.a) + e->mvmnt.a *
	sin(e->p.a + M_PI / 2) + e->mvmnt.s * sin(e->p.a + M_PI) + e->mvmnt.d *
	sin(e->p.a + 3 * M_PI / 2);
}

void		ft_key_press_comp(t_elem *e)
{
	float	xcomp;
	float	ycomp;
	int		gridx;
	int		gridy;

	ft_increment_pangle(e, (float)e->mvmnt.an * ROTATION_SPEED);
	ft_fill_comp(e, &xcomp, &ycomp);
	gridy = lround(e->p.y / CUBE_S);
	gridx = (e->p.x + lround(xcomp * MOVE_SPEED)) / CUBE_S;
	e->p.x += lround(xcomp * MOVE_SPEED);
	gridy = (e->p.y - lround(ycomp * MOVE_SPEED)) / CUBE_S;
	gridx = lround(e->p.x / CUBE_S);
	e->p.y -= lround(ycomp * MOVE_SPEED);
}
