/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:15:09 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 17:04:42 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static float	ft_find_rangle(t_elem *e, int ray)
{
	float	ra;

	ra = e->p.a + atan((e->cst.schl - e->cst.seglen * ray) / e->cst.scdist);
	if (ra < 0)
		ra += 2 * M_PI;
	if (ra >= 2 * M_PI)
		ra = ra - 2 * M_PI;
	return (ra);
}

static void		ft_draw_pixel_row(t_elem *e, int x, char wallc, float ray)
{
	int y;
	int wallh;

	if (ray == 0)
		wallh = e->ry;
	else
		wallh = CUBE_S * e->cst.scdist / ray;
	y = 0;
	while (y < (e->ry - wallh) / 2 && y < e->ry)
	{
		e->cimg.data[y * e->rx + x] = e->c.c;
		y++;
	}
	while (y <= (e->ry - wallh) / 2 + wallh && y < e->ry)
	{
		e->cimg.data[y * e->rx + x] = ft_get_tcolor(e,
								wallh, y - (e->ry - wallh) / 2, wallc);
		y++;
	}
	while (y < e->ry)
	{
		e->cimg.data[y * e->rx + x] = e->c.f;
		y++;
	}
}

static float	ft_find_dist_ray(t_elem *e, int prec, float ra)
{
	float		dx;
	float		dy;

	dx = ft_find_dist_rayx(e, ra, prec) * fabs(cos(ra - e->p.a));
	if (ra != 0 && ra != M_PI)
		ft_sprite_exist(e, ra, dx);
	dy = ft_find_dist_rayy(e, ra, prec) * fabs(cos(ra - e->p.a));
	if (ra != M_PI / 2 && ra != 3 * M_PI / 2)
		ft_sprite_exist(e, ra, dy);
	if ((dx <= dy && ra != 0 && ra != M_PI) ||
				ra == M_PI / 2 || ra == 3 * M_PI / 2)
	{
		ft_fill_wall_param(e, ra, prec, 1);
		return (dx);
	}
	ft_fill_wall_param(e, ra, prec, 0);
	return (dy);
}

void			ft_display_walls(t_elem *e)
{
	int		x;
	float	ray;

	x = 0;
	while (x < e->rx)
	{
		e->rayan = ft_find_rangle(e, x);
		ray = ft_find_dist_ray(e, CUBE_S, e->rayan);
		ft_draw_pixel_row(e, x, e->wallc, ray);
		if (e->sp)
		{
			ft_sort_sprites(&e->sp);
			ft_draw_sprites(e, x, ray / fabs(cos(e->rayan - e->p.a)));
			ft_free_sprites(&e->sp);
		}
		x++;
	}
}
