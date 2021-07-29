/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_to_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:51:24 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 13:45:43 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_img_to_mlx_img(t_elem *e, t_img *img, char *path)
{
	if (ft_strrncmp(path, ".png", 3) == 0)
		img->ptr = mlx_png_file_to_image(e->m_ptr, path, &img->rx, &img->ry);
	if (ft_strrncmp(path, ".xpm", 3) == 0)
		img->ptr = mlx_xpm_file_to_image(e->m_ptr, path, &img->rx, &img->ry);
	if (!img->ptr)
		ft_disp_error_msg(e, "Wrong img path\n", NULL);
	img->data = (unsigned int *)mlx_get_data_addr(img->ptr,
							&img->bpp, &img->l, &img->end);
	if (!img->data)
		ft_disp_error_msg(e, "Wrong img path\n", NULL);
}
