/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_color_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:58:49 by olidon            #+#    #+#             */
/*   Updated: 2020/03/02 15:25:12 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static unsigned int	ft_return_img_color(t_elem *e, int wallh,
													int yoffset, t_img img)
{
	int		x;
	int		y;
	float	ratio;

	ratio = (float)img.rx / (float)img.ry;
	if (ratio < 1 && (e->offset < (CUBE_S - CUBE_S * ratio) / 2
			|| e->offset > (CUBE_S - CUBE_S * ratio) / 2 + CUBE_S * ratio))
		return (0xFF000000);
	if (ratio > 1 && (yoffset < (wallh - wallh / ratio) / 2
			|| yoffset > (wallh - wallh / ratio) / 2 + wallh / ratio))
		return (0xFF000000);
	if (wallh == 0)
		y = 0;
	else
		y = (float)(yoffset - 1) * (float)img.ry / (float)wallh;
	x = e->offset * img.rx / CUBE_S;
	if (y > img.ry)
		y = img.ry;
	if (x > img.rx)
		x = img.rx;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	return (img.data[y * img.rx + x]);
}

unsigned int		ft_get_tcolor(t_elem *e, int wallh,
												int yoffset, char wallc)
{
	if (wallc == 'S')
		return (ft_return_img_color(e, wallh, yoffset, e->t.no));
	if (wallc == 'N')
		return (ft_return_img_color(e, wallh, yoffset, e->t.so));
	if (wallc == 'W')
		return (ft_return_img_color(e, wallh, yoffset, e->t.ea));
	if (wallc == 'P')
	{
		if (e->cst.loop >= 0 && e->cst.loop <= 5)
			return (ft_return_img_color(e, wallh, yoffset, e->t.s));
		if (e->cst.loop >= 6 && e->cst.loop <= 11)
			return (ft_return_img_color(e, wallh, yoffset, e->t.s1));
	}
	if (wallc == 'D')
		return (ft_return_img_color(e, wallh, yoffset, e->t.s2));
	if (wallc == 'H')
		return (ft_return_img_color(e, wallh, yoffset, e->t.s3));
	return (ft_return_img_color(e, wallh, yoffset, e->t.we));
}
