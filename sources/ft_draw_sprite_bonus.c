/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:57:57 by olidon            #+#    #+#             */
/*   Updated: 2020/02/27 10:47:53 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void			ft_dec_col_to_argb(t_argb *col, unsigned int color)
{
	(*col).a = (color >> 24) & 0xFF;
	(*col).r = (color >> 16) & 0xFF;
	(*col).g = (color >> 8) & 0xFF;
	(*col).b = (color >> 0) & 0xFF;
}

static unsigned int	ft_combine_alpha_color(t_elem *e,
											unsigned int color, int x, int y)
{
	t_argb	bkgcol;
	t_argb	sprcol;

	ft_dec_col_to_argb(&bkgcol, e->cimg.data[y * e->rx + x]);
	ft_dec_col_to_argb(&sprcol, color);
	if (sprcol.a == 255)
		color = 0xFF000000;
	else
	{
		bkgcol.r = (unsigned char)(bkgcol.r + (int)((sprcol.r
		- bkgcol.r) * (1 - ((float)sprcol.a / 255))));
		bkgcol.g = (unsigned char)(bkgcol.g + (int)((sprcol.g
		- bkgcol.g) * (1 - ((float)sprcol.a / 255))));
		bkgcol.b = (unsigned char)(bkgcol.b + (int)((sprcol.b
		- bkgcol.b) * (1 - ((float)sprcol.a / 255))));
		color = bkgcol.a * 256 * 256 * 256 + bkgcol.r * 256 * 256
												+ bkgcol.g * 256 + bkgcol.b;
	}
	return (color);
}

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
		if (color > 0x00FFFFFF)
			color = ft_combine_alpha_color(e, color, x, y);
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
			if (cs->dead == 1)
				ft_draw_sprite_row(e, x, 'D', wallh);
			else if (cs->shoot == 1)
				ft_draw_sprite_row(e, x, 'H', wallh);
			else
				ft_draw_sprite_row(e, x, 'P', wallh);
		}
		cs = cs->next;
	}
}
