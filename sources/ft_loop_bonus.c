/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:56 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:48:20 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_move_sprites_pos(t_sprpos *sprpos)
{
	t_sprpos	*current;
	int			i;

	i = 0;
	current = sprpos;
	while (current)
	{
		if (current->dist > CUBE_S * 2 && current->vis == 1
													&& current->life != 0)
		{
			current->x -= cos(current->angle) * (i + 2) * MOVE_SPEED;
			current->y += sin(current->angle) * (i + 2) * MOVE_SPEED;
			current->shoot = 0;
		}
		else if (current->dist <= CUBE_S * 2 &&
									current->vis == 1 && current->life != 0)
			current->shoot = 1;
		current->vis = 0;
		current = current->next;
		i++;
	}
}

static void	ft_sprite_loose_life(t_elem *e)
{
	t_sprpos	*current;

	if (!e->sprpos)
		return ;
	current = e->sprpos;
	while (current)
	{
		if (current->dist != 0 && current->vis == 1)
		{
			if (e->p.a > current->angle - fabs(atan((CUBE_S / 4) /
			current->dist)) && e->p.a < current->angle +
			fabs(atan((CUBE_S / 4) / current->dist)) && e->mvmnt.ml == 1)
				if (--(current->life) < 0)
					current->life = 0;
		}
		if (current->vis == 1 && current->shoot == 1 && current->life > 0)
			e->cst.life -= 1;
		current = current->next;
	}
}

static void	ft_black_screen(t_img img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < img.ry)
	{
		while (j < img.rx)
		{
			img.data[i * img.rx + j] = 0x00000000;
			j++;
		}
		j = 0;
		i++;
	}
}

static void	ft_disp_imgs_to_win(t_elem *e)
{
	mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->cimg.ptr, 0, 0);
	mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->mimg.ptr,
	e->rx / 380, e->ry / 216);
	if (e->mvmnt.ml == 1)
		mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->t.w2sc.ptr,
						e->rx / 2 - e->t.w2sc.rx / 2, e->ry - e->t.w2sc.ry);
	else
		mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->t.w1sc.ptr,
						e->rx / 2 - e->t.w1sc.rx / 2, e->ry - e->t.w1sc.ry);
	mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->t.pointsc.ptr,
		e->rx / 2 - e->t.pointsc.rx / 2, e->ry / 2 - e->t.pointsc.ry / 2);
	mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->t.lifesc.ptr,
								e->cst.life, e->ry - e->t.lifesc.ry - 10);
}

int			ft_move_loop(t_elem *e)
{
	int	x;
	int	y;

	if (++e->cst.loop > 11)
		e->cst.loop = 0;
	ft_key_press_comp(e);
	mlx_mouse_get_pos(e->w_ptr, &x, &y);
	ft_motion_hook(x, y, e);
	ft_display_minimap(e, 0, 0);
	ft_display_walls(e);
	ft_sprite_loose_life(e);
	if (e->cst.loop == 11)
		ft_move_sprites_pos(e->sprpos);
	if (e->mvmnt.sprint == 1)
		e->cst.sprint--;
	if (e->cst.life <= -500 * e->rx / 1920)
	{
		ft_black_screen(e->cimg);
		mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->cimg.ptr, 0, 0);
		mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->t.deadsc.ptr, e->rx
					/ 2 - e->t.deadsc.rx / 2, e->ry / 2 - e->t.deadsc.ry / 2);
	}
	else
		ft_disp_imgs_to_win(e);
	return (0);
}
