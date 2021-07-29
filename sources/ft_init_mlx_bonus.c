/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:14:08 by olidon            #+#    #+#             */
/*   Updated: 2020/03/02 14:23:12 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	e->mvmnt.ml = 0;
	e->mvmnt.an = 0;
	e->mvmnt.sprint = 0;
	e->mvmnt.mousey = -10;
	e->mvmnt.mousex = e->rx / 2;
	e->cst.life = 0;
	e->cst.loop = 0;
	e->cst.sprint = 200;
}

static void	ft_fill_scaled_img(t_elem *e, t_img *imga, t_img *imgb)
{
	int	x;
	int	y;
	int	scalex;
	int	scaley;

	x = 0;
	y = 0;
	imga->rx = (float)imgb->rx * ((float)e->rx / (float)1920);
	imga->ry = (float)imgb->ry * ((float)e->ry / (float)1080);
	imga->ptr = mlx_new_image(e->m_ptr, imga->rx, imga->ry);
	imga->data = (unsigned int *)mlx_get_data_addr(imga->ptr,
					&imga->bpp, &imga->l, &imga->end);
	while (y < imga->ry)
	{
		while (x < imga->rx)
		{
			scalex = (float)x * ((float)imgb->rx / (float)imga->rx);
			scaley = (float)y * ((float)imgb->ry / (float)imga->ry);
			imga->data[y * imga->rx + x] =
			imgb->data[scaley * imgb->rx + scalex];
			x++;
		}
		x = 0;
		y++;
	}
}

static void	ft_scale_hud(t_elem *e)
{
	ft_img_to_mlx_img(e, &e->t.w1, "./Textures/weapon/Weapon1.xpm");
	ft_img_to_mlx_img(e, &e->t.w2, "./Textures/weapon/Weapon3.xpm");
	ft_img_to_mlx_img(e, &e->t.point, "./Textures/HUD/pointer.png");
	ft_img_to_mlx_img(e, &e->t.life, "./Textures/HUD/life.png");
	ft_img_to_mlx_img(e, &e->t.dead, "./Textures/HUD/youdied.xpm");
	ft_fill_scaled_img(e, &e->t.w1sc, &e->t.w1);
	ft_fill_scaled_img(e, &e->t.w2sc, &e->t.w2);
	ft_fill_scaled_img(e, &e->t.pointsc, &e->t.point);
	ft_fill_scaled_img(e, &e->t.lifesc, &e->t.life);
	ft_fill_scaled_img(e, &e->t.deadsc, &e->t.dead);
	mlx_destroy_image(e->m_ptr, e->t.w1.ptr);
	mlx_destroy_image(e->m_ptr, e->t.w2.ptr);
	mlx_destroy_image(e->m_ptr, e->t.point.ptr);
	mlx_destroy_image(e->m_ptr, e->t.life.ptr);
	mlx_destroy_image(e->m_ptr, e->t.dead.ptr);
}

static void	ft_init_img(t_elem *e)
{
	ft_img_to_mlx_img(e, &e->t.ea, e->t.eap);
	ft_img_to_mlx_img(e, &e->t.no, e->t.nop);
	ft_img_to_mlx_img(e, &e->t.so, e->t.sop);
	ft_img_to_mlx_img(e, &e->t.we, e->t.wep);
	ft_img_to_mlx_img(e, &e->t.s, e->t.sp);
	ft_img_to_mlx_img(e, &e->t.s1, "./Textures/npc/npcmove3.xpm");
	ft_img_to_mlx_img(e, &e->t.s2, "./Textures/npc/npcdeath4.xpm");
	ft_img_to_mlx_img(e, &e->t.s3, "./Textures/npc/npcshoot3.xpm");
	ft_scale_hud(e);
	e->cimg.rx = e->rx;
	e->cimg.ry = e->ry;
	e->cimg.ptr = mlx_new_image(e->m_ptr, e->cimg.rx, e->cimg.ry);
	e->cimg.data = (unsigned int *)mlx_get_data_addr(e->cimg.ptr,
								&e->cimg.bpp, &e->cimg.l, &e->cimg.end);
	e->mimg.rx = e->rx / 12;
	e->mimg.ry = e->ry / 6.75;
	e->mimg.ptr = mlx_new_image(e->m_ptr, e->mimg.rx, e->mimg.ry);
	e->mimg.data = (unsigned int *)mlx_get_data_addr(e->mimg.ptr,
								&e->mimg.bpp, &e->mimg.l, &e->mimg.end);
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
		mlx_mouse_move(e->w_ptr, e->rx / 2, e->ry / 2);
		mlx_mouse_hide();
		mlx_hook(e->w_ptr, 17, 0, ft_exit_windows, e);
		mlx_hook(e->w_ptr, 6, 0, ft_motion_hook, e);
		mlx_hook(e->w_ptr, 4, 0, ft_mouse_press, e);
		mlx_hook(e->w_ptr, 2, 0, ft_key_press, e);
		mlx_hook(e->w_ptr, 5, 0, ft_mouse_release, e);
		mlx_hook(e->w_ptr, 3, 0, ft_key_release, e);
	}
	else
	{
		ft_display_minimap(e, 0, 0);
		ft_display_walls(e);
		ft_mlx_img_to_bmp(e, e->cimg, 0, 0);
	}
	mlx_loop_hook(e->m_ptr, ft_move_loop, e);
	mlx_loop(e->m_ptr);
}
