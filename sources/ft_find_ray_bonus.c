/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ray_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:02:19 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:47:05 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		ft_sprite_exist(t_elem *e, float ra, float ray)
{
	t_sprpos	*current;

	if (!e->sprpos)
		return ;
	current = e->sprpos;
	while (current)
	{
		current->dist = sqrt(pow(e->p.x - current->x, 2) +
											pow(e->p.y - current->y, 2));
		if (current->dist < ray && current->dist != 0)
		{
			current->angle = ft_find_sprite_angle(e, current->x, current->y,
															current->dist);
			if (fabs(ft_mod_pib(current->angle - ra)) <
									fabs(atan((CUBE_S / 2) / current->dist)))
			{
				current->vis = 1;
				ft_fill_sprite_struct(e, ra, current, current->angle);
			}
		}
		current = current->next;
	}
}

float		ft_find_dist_rayx(t_elem *e, float ra, int prec)
{
	int		gridx;
	int		gridy;

	e->rayx.ay = ft_find_rayx_ay(ra, e, prec);
	e->rayx.ya = ft_find_rayx_ya(ra, prec);
	e->rayx.ax = ft_find_rayx_ax(ra, e->rayx.ay, e);
	e->rayx.xa = ft_find_rayx_xa(ra, prec);
	gridx = e->rayx.ax / prec;
	gridy = e->rayx.ay / prec;
	while (gridy <= e->msy && gridx <= e->msx && gridx >= 0 &&
					gridy >= 0 && e->map[gridy][gridx] != '1')
	{
		e->rayx.ax += e->rayx.xa;
		e->rayx.ay += e->rayx.ya;
		gridx = e->rayx.ax / prec;
		gridy = e->rayx.ay / prec;
	}
	return (sqrt(pow(e->p.x - e->rayx.ax, 2) + pow(e->p.y - e->rayx.ay, 2)));
}

float		ft_find_dist_rayy(t_elem *e, float ra, int prec)
{
	int		gridx;
	int		gridy;

	e->rayy.ax = ft_find_rayy_ax(ra, e, prec);
	e->rayy.xa = ft_find_rayy_xa(ra, prec);
	e->rayy.ay = ft_find_rayy_ay(ra, e->rayy.ax, e);
	e->rayy.ya = ft_find_rayy_ya(ra, prec);
	gridx = e->rayy.ax / prec;
	gridy = e->rayy.ay / prec;
	while (gridy <= e->msy && gridx <= e->msx && gridx >= 0 &&
					gridy >= 0 && e->map[gridy][gridx] != '1')
	{
		e->rayy.ax += e->rayy.xa;
		e->rayy.ay += e->rayy.ya;
		gridx = e->rayy.ax / prec;
		gridy = e->rayy.ay / prec;
	}
	return (sqrt(pow(e->p.x - e->rayy.ax, 2) + pow(e->p.y - e->rayy.ay, 2)));
}

static void	ft_find_ray_minimap(t_elem *e, float *x, float *y)
{
	*x = (*x / CUBE_S - e->p.x / CUBE_S) * 10 + e->mimg.rx / 2;
	*y = (*y / CUBE_S - e->p.y / CUBE_S) * 10 + e->mimg.ry / 2;
}

void		ft_fill_wall_param(t_elem *e, float ra, int prec, int dx)
{
	if (dx == 1)
	{
		e->wallc = 'S';
		e->offset = prec - (int)e->rayx.ax % prec - 1;
		if (ra > 0 && ra < M_PI)
		{
			e->offset = (int)e->rayx.ax % prec;
			e->wallc = 'N';
		}
		ft_find_ray_minimap(e, &e->rayx.ax, &e->rayx.ay);
		ft_draw_line(e, e->rayx.ax, e->rayx.ay);
		return ;
	}
	e->wallc = 'E';
	e->offset = (int)e->rayy.ay % prec;
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
	{
		e->offset = prec - (int)e->rayy.ay % prec - 1;
		e->wallc = 'W';
	}
	ft_find_ray_minimap(e, &e->rayy.ax, &e->rayy.ay);
	ft_draw_line(e, e->rayy.ax, e->rayy.ay);
	return ;
}
