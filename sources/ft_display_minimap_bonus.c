/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_minimap_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:02:50 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:46:05 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	ft_find_eq(t_elem *e, int xb, int yb)
{
	if (abs(xb - e->l.xa) > abs(yb - e->l.ya))
		return (abs(xb - e->l.xa) / 2);
	else
		return (-abs(yb - e->l.ya) / 2);
}

void		ft_draw_line(t_elem *e, int xb, int yb)
{
	int eq;

	e->l.xa = e->mimg.rx / 2;
	e->l.ya = e->mimg.ry / 2;
	eq = ft_find_eq(e, xb, yb);
	while (e->l.xa != xb && e->l.ya != yb && xb < e->mimg.rx
	&& yb < e->mimg.ry && xb >= 0 && yb >= 0)
	{
		e->mimg.data[e->l.ya * e->mimg.rx + e->l.xa] = 0x88ffff3d;
		if (eq > -abs(xb - e->l.xa))
		{
			eq -= abs(yb - e->l.ya);
			e->l.xa -= 1;
			if (e->l.xa < xb)
				e->l.xa += 2;
		}
		if (eq < abs(yb - e->l.ya))
		{
			eq += abs(xb - e->l.xa);
			e->l.ya -= 1;
			if (e->l.ya < yb)
				e->l.ya += 2;
		}
	}
}

static void	ft_draw_sqfive(t_elem *e, int i, int j, int color)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < 5 && (k + j) < e->mimg.rx && (k + j) >= 0)
	{
		while (l < 5 && (l + i) < e->mimg.ry && (l + i) >= 0)
		{
			e->mimg.data[(i + l) * e->mimg.rx + (j + k)] = color;
			l++;
		}
		l = 0;
		k++;
	}
}

static void	ft_draw_sqten(t_elem *e, int y, int x, int color)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < 10 && (k + x) < e->mimg.rx && (k + x) >= 0)
	{
		while (l < 10 && (l + y) < e->mimg.ry && (l + y) >= 0)
		{
			e->mimg.data[(y + l) * e->mimg.rx + (x + k)] = color;
			l++;
		}
		l = 0;
		k++;
	}
}

void		ft_display_minimap(t_elem *e, int i, int j)
{
	int		x;
	int		y;

	x = e->p.x / CUBE_S - e->mimg.rx / 20;
	y = e->p.y / CUBE_S - e->mimg.ry / 20;
	while (y <= e->p.y / CUBE_S + e->mimg.ry / 20 + 10
	&& i <= e->mimg.ry / 10 + 10)
	{
		while (x <= e->p.x / CUBE_S + e->mimg.rx / 20 + 10
		&& j <= e->mimg.rx / 10 + 10)
		{
			if (y >= 0 && x >= 0 && y < e->msy && x < e->msx &&
														e->map[y][x] != '1')
				ft_draw_sqten(e, i * 10, j * 10, 0x88000000);
			else
				ft_draw_sqten(e, i * 10, j * 10, 0x88FFFFFF);
			x++;
			j++;
		}
		x = e->p.x / CUBE_S - e->mimg.rx / 20;
		j = 0;
		y++;
		i++;
	}
	ft_draw_sqfive(e, e->mimg.ry / 2 - 2, e->mimg.rx / 2 - 2, 0x004CB285);
}
