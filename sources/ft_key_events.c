/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:37:22 by olidon            #+#    #+#             */
/*   Updated: 2020/02/24 12:47:55 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	else if (keycode == 53)
		ft_free_struct_elem(e);
	return (0);
}
