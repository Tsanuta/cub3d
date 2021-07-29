/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:43:14 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 15:18:54 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	ft_check_color_range(t_elem *e, char *linecp,
											char *lineb, int *str)
{
	int				j;
	unsigned int	i;

	if (linecp)
		free(linecp);
	j = -1;
	while (++j < 3)
	{
		if (str[j] < 0 || str[j] > 255)
			ft_disp_error_msg(e, "Invalid color range.\n", lineb);
	}
	i = str[0] * 256 * 256 + str[1] * 256 + str[2];
	return (i);
}

static void		ft_check_res(t_elem *elem, char *line, char *lineb)
{
	int	i;

	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
		ft_disp_error_msg(elem, "Too many arguments for resolution.\n", lineb);
}

void			ft_fill_res(t_elem *elem, char *line, char *lineb)
{
	int		i;

	i = 1;
	if (elem->exres == 1)
		ft_disp_error_msg(elem, "Too many lines for resolution.\n", lineb);
	elem->exres = 1;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && (line[i] < '0' || line[i] > '9'))
		ft_disp_error_msg(elem, "Invalid X resolution syntax.\n", lineb);
	if ((elem->rx = ft_atoi(&line[i])) < 1)
		ft_disp_error_msg(elem, "X resolution must be 1 or more.\n", lineb);
	if (elem->rx > 2560)
		elem->rx = 2560;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && (line[i] < '0' || line[i] > '9'))
		ft_disp_error_msg(elem, "Invalid Y resolution syntax.\n", lineb);
	if ((elem->ry = ft_atoi(&line[i])) < 1)
		ft_disp_error_msg(elem, "Y resolution must be 1 or more.\n", lineb);
	if (elem->ry > 1440)
		elem->ry = 1440;
	ft_check_res(elem, &line[i], line);
}

char			*ft_fill_path(t_elem *e, char *line, char *lineb)
{
	int		i;
	int		slen;
	char	*path;

	i = 0;
	slen = 0;
	if (line[i] == 'S' && line[i + 1] != 'O')
		i++;
	else
		i += 2;
	if (!(path = ft_strtrim(&line[i], " ")))
		ft_disp_error_msg(e, "Trim spaces on path.\n", lineb);
	if (!path || path[0] == '\0')
		ft_disp_error_msg(e, "Missing texture path.\n", lineb);
	if (ft_strrncmp(path, ".png", 3) != 0 && ft_strrncmp(path, ".xpm", 3) != 0)
		ft_disp_error_msg(e, "Invalid text img. Use xpm or png.\n", lineb);
	return (path);
}

void			ft_fill_player_pos(t_elem *e, int i, int j)
{
	e->p.x = j * CUBE_S + CUBE_S / 2;
	e->p.y = i * CUBE_S + CUBE_S / 2;
	if (e->map[i][j] == 'N')
		e->p.a = M_PI / 2;
	if (e->map[i][j] == 'E')
		e->p.a = 0;
	if (e->map[i][j] == 'S')
		e->p.a = 3 * M_PI / 2;
	if (e->map[i][j] == 'W')
		e->p.a = M_PI;
	e->map[i][j] = '0';
}
