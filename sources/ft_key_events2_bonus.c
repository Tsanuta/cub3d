/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:10:01 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:48:12 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	*xcomp = e->mvmnt.w * cos(e->p.a) * (1 + e->mvmnt.sprint) + e->mvmnt.a *
	cos(e->p.a + M_PI / 2) + e->mvmnt.s * cos(e->p.a + M_PI) + e->mvmnt.d *
	cos(e->p.a + 3 * M_PI / 2);
	*ycomp = e->mvmnt.w * sin(e->p.a) * (1 + e->mvmnt.sprint) + e->mvmnt.a *
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
	if (gridy <= e->msy && gridx <= e->msx && gridx >= 0 &&
					gridy >= 0 && e->map[gridy][gridx] != '1')
		e->p.x += lround(xcomp * MOVE_SPEED);
	else if (gridy <= e->msy && (e->p.x + lround(xcomp)) / CUBE_S <= e->msx
	&& (e->p.x + lround(xcomp)) / CUBE_S >= 0 && gridy >= 0
	&& e->map[gridy][(e->p.x + lround(xcomp)) / CUBE_S] != '1')
		e->p.x += lround(xcomp);
	gridy = (e->p.y - lround(ycomp * MOVE_SPEED)) / CUBE_S;
	gridx = lround(e->p.x / CUBE_S);
	if (gridy <= e->msy && gridx <= e->msx && gridx >= 0 &&
					gridy >= 0 && e->map[gridy][gridx] != '1')
		e->p.y -= lround(ycomp * MOVE_SPEED);
	else if ((e->p.y - lround(ycomp)) / CUBE_S <= e->msy && gridx <= e->msx
	&& gridx >= 0 && (e->p.y - lround(ycomp)) / CUBE_S >= 0
	&& e->map[(e->p.y - lround(ycomp)) / CUBE_S][gridx] != '1')
		e->p.y += lround(ycomp);
}
