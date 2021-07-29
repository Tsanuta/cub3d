/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:37:22 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:48:06 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_mouse_press(int keycode, int x, int y, t_elem *e)
{
	if (keycode == 1)
		e->mvmnt.ml = 1;
	e->mvmnt.mousex = x;
	e->mvmnt.mousey = y;
	return (0);
}

int	ft_mouse_release(int keycode, int x, int y, t_elem *e)
{
	if (keycode == 1)
		e->mvmnt.ml = 0;
	e->mvmnt.mousex = x;
	e->mvmnt.mousey = y;
	return (0);
}

int	ft_motion_hook(int x, int y, t_elem *e)
{
	if (e->mvmnt.mousex == x)
	{
		if (e->mvmnt.mousex != e->rx / 2)
		{
			mlx_mouse_move(e->w_ptr, e->rx / 2, e->ry / 2);
			e->mvmnt.an = 0;
			e->mvmnt.mousex = e->rx / 2;
		}
	}
	else
	{
		e->mvmnt.mousex = x;
		if (x < e->rx / 2 - 5)
			e->mvmnt.an = 1;
		if (x > e->rx / 2 + 5)
			e->mvmnt.an = -1;
	}
	e->mvmnt.mousey = y;
	return (0);
}

int	ft_key_release(int keycode, t_elem *e)
{
	if (keycode == 13)
		e->mvmnt.w = 0;
	else if (keycode == 0)
		e->mvmnt.a = 0;
	else if (keycode == 1)
		e->mvmnt.s = 0;
	else if (keycode == 2)
		e->mvmnt.d = 0;
	else if (keycode == 123)
		e->mvmnt.an = 0;
	else if (keycode == 124)
		e->mvmnt.an = 0;
	else if (keycode == 257)
		e->mvmnt.sprint = 0;
	else if (keycode == 53)
		ft_free_struct_elem(e);
	return (0);
}

int	ft_key_press(int keycode, t_elem *e)
{
	if (keycode == 13)
		e->mvmnt.w = 1;
	else if (keycode == 0)
		e->mvmnt.a = 1;
	else if (keycode == 1)
		e->mvmnt.s = 1;
	else if (keycode == 2)
		e->mvmnt.d = 1;
	else if (keycode == 123)
		e->mvmnt.an = 1;
	else if (keycode == 124)
		e->mvmnt.an = -1;
	else if (keycode == 257)
		e->mvmnt.sprint = 1;
	else if (keycode == 53)
		ft_free_struct_elem(e);
	return (0);
}
