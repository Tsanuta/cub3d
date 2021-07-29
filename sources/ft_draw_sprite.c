/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:57:57 by olidon            #+#    #+#             */
/*   Updated: 2020/02/25 14:13:53 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void			ft_draw_sprite_row(t_elem *e, int x, char wallc, int wallh)
{
	int				y;
	unsigned int	color;

	y = 0;
	while (y < (e->ry - wallh) / 2 && y < e->ry)
		y++;
	while (y <= (e->ry - wallh) / 2 + wallh && y < e->ry)
	{
		color = ft_get_tcolor(e, wallh, y - (e->ry - wallh) / 2, wallc);
		if (color < 0xFF000000)
			e->cimg.data[y * e->rx + x] = color;
		y++;
	}
}

void				ft_draw_sprites(t_elem *e, int x, float ray)
{
	int			wallh;
	t_sprite	*cs;

	cs = e->sp;
	while (cs)
	{
		if (cs->dist < ray && cs->offset != -1)
		{
			e->offset = cs->offset;
			wallh = CUBE_S * e->cst.scdist / cs->dist;
			ft_draw_sprite_row(e, x, 'P', wallh);
		}
		cs = cs->next;
	}
}
