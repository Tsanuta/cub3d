/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:33:56 by olidon            #+#    #+#             */
/*   Updated: 2020/02/24 12:48:59 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_move_loop(t_elem *e)
{
	ft_key_press_comp(e);
	ft_display_walls(e);
	mlx_put_image_to_window(e->m_ptr, e->w_ptr, e->cimg.ptr, 0, 0);
	return (0);
}
