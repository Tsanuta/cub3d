/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img_bmp_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:44:42 by olidon            #+#    #+#             */
/*   Updated: 2020/03/02 13:25:27 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_strcpynoend(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
}

static char	*ft_int_to_chararray(t_elem *e, unsigned int nb)
{
	char	*nbr;

	if (!(nbr = malloc(sizeof(char) * 5)))
		ft_disp_error_msg(e, "Malloc nbr error\n", NULL);
	nbr[4] = '\0';
	nbr[0] = (nb >> 0) & 0xFF;
	nbr[1] = (nb >> 8) & 0xFF;
	nbr[2] = (nb >> 16) & 0xFF;
	nbr[3] = (nb >> 24) & 0xFF;
	return (nbr);
}

static void	ft_fill_bmp_color(t_elem *e, t_img img, int offx, int offy)
{
	int	x;
	int	y;
	int	i;

	offx = 0;
	offy = 0;
	x = 0;
	y = img.ry - 1;
	i = 0;
	while (y > -1)
	{
		while (x < img.rx)
		{
			ft_strcpynoend(&e->bmp[54 + i * 4],
				ft_int_to_chararray(e, img.data[y * img.rx + x]), 4);
			x++;
			i++;
		}
		x = 0;
		y--;
	}
}

static void	ft_fill_bmp_header(t_elem *e, char **bmp, int bmplen, t_img img)
{
	(*bmp)[0] = 'B';
	(*bmp)[1] = 'M';
	ft_strcpynoend(&(*bmp)[2], ft_int_to_chararray(e, bmplen), 4);
	(*bmp)[6] = 0;
	(*bmp)[7] = 0;
	(*bmp)[8] = 0;
	(*bmp)[9] = 0;
	ft_strcpynoend(&(*bmp)[10], ft_int_to_chararray(e, 54), 4);
	ft_strcpynoend(&(*bmp)[14], ft_int_to_chararray(e, 40), 4);
	ft_strcpynoend(&(*bmp)[18], ft_int_to_chararray(e, img.rx), 4);
	ft_strcpynoend(&(*bmp)[22], ft_int_to_chararray(e, img.ry), 4);
	(*bmp)[26] = 1;
	(*bmp)[27] = 0;
	(*bmp)[28] = 32;
	(*bmp)[29] = 0;
	ft_strcpynoend(&(*bmp)[30], ft_int_to_chararray(e, 0), 4);
	ft_strcpynoend(&(*bmp)[34], ft_int_to_chararray(e, bmplen), 4);
	ft_strcpynoend(&(*bmp)[38], ft_int_to_chararray(e, 800), 4);
	ft_strcpynoend(&(*bmp)[42], ft_int_to_chararray(e, 800), 4);
	ft_strcpynoend(&(*bmp)[46], ft_int_to_chararray(e, 0), 4);
	ft_strcpynoend(&(*bmp)[50], ft_int_to_chararray(e, 0), 4);
}

void		ft_mlx_img_to_bmp(t_elem *e, t_img img, int offx, int offy)
{
	int		fd;
	int		bmplen;

	bmplen = 14 + 40 + e->rx * e->ry * 4;
	if (!(e->bmp = malloc(sizeof(char) * (bmplen + 1))))
		ft_disp_error_msg(e, "Malloc error\n", NULL);
	e->bmp[bmplen] = '\0';
	ft_fill_bmp_header(e, &e->bmp, bmplen, img);
	ft_fill_bmp_color(e, img, offx, offy);
	if ((fd = open("./save.bmp", O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU)) < 0)
		ft_disp_error_msg(e, "Can't read or create img file\n", NULL);
	write(fd, e->bmp, bmplen);
	close(fd);
	ft_free_struct_elem(e);
}
