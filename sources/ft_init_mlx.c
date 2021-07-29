/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:14:08 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 13:41:50 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_const(t_elem *e)
{
	e->cst.fov = FOV * M_PI / 180;
	e->cst.scdist = (e->rx / 2) / tan(FOV * M_PI / 180 / 2);
	e->cst.schl = tan(e->cst.fov / 2) * e->cst.scdist;
	e->cst.seglen = e->cst.schl / (e->rx / 2);
	e->mvmnt.a = 0;
	e->mvmnt.d = 0;
	e->mvmnt.w = 0;
	e->mvmnt.s = 0;
	e->mvmnt.an = 0;
}

static void	ft_init_img(t_elem *e)
{
	ft_img_to_mlx_img(e, &e->t.ea, e->t.eap);
	ft_img_to_mlx_img(e, &e->t.no, e->t.nop);
	ft_img_to_mlx_img(e, &e->t.so, e->t.sop);
	ft_img_to_mlx_img(e, &e->t.we, e->t.wep);
	ft_img_to_mlx_img(e, &e->t.s, e->t.sp);
	e->cimg.rx = e->rx;
	e->cimg.ry = e->ry;
	e->cimg.ptr = mlx_new_image(e->m_ptr, e->cimg.rx, e->cimg.ry);
	e->cimg.data = (unsigned int *)mlx_get_data_addr(e->cimg.ptr,
								&e->cimg.bpp, &e->cimg.l, &e->cimg.end);
}

void		ft_display(t_elem *e)
{
	ft_init_const(e);
	if (!(e->m_ptr = mlx_init()))
		ft_disp_error_msg(e, "Fail to init mlx", NULL);
	ft_init_img(e);
	if (e->save == 0)
	{
		if (!(e->w_ptr = mlx_new_window(e->m_ptr, e->rx, e->ry, "cub3d")))
			ft_disp_error_msg(e, "Fail to open mlx new window", NULL);
		mlx_hook(e->w_ptr, 17, 0, ft_exit_windows, e);
		mlx_hook(e->w_ptr, 2, 0, ft_key_press, e);
		mlx_hook(e->w_ptr, 3, 0, ft_key_release, e);
	}
	else
	{
		ft_display_walls(e);
		ft_mlx_img_to_bmp(e, e->cimg, 0, 0);
	}
	mlx_loop_hook(e->m_ptr, ft_move_loop, e);
	mlx_loop(e->m_ptr);
}
