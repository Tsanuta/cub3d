/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap6_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:56:29 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 15:42:01 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void			ft_case_flood_fill(t_elem *e, int x, int y)
{
	if (x >= 0 && y >= 0 && y <= e->msy && x < (int)ft_strlen(e->mapcp[y])
	&& ft_strchr("ESNW02", e->mapcp[y][x]) != 0)
	{
		e->mapcp[y][x] = '3';
		ft_case_flood_fill(e, x - 1, y - 1);
		ft_case_flood_fill(e, x, y - 1);
		ft_case_flood_fill(e, x + 1, y - 1);
		ft_case_flood_fill(e, x + 1, y);
		ft_case_flood_fill(e, x + 1, y + 1);
		ft_case_flood_fill(e, x, y + 1);
		ft_case_flood_fill(e, x - 1, y + 1);
		ft_case_flood_fill(e, x - 1, y);
	}
	return ;
}

static void		ft_case_search_walls(t_elem *e, int x, int y)
{
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 <= e->msy && x + 1 <
	(int)ft_strlen(e->mapcp[y]) && x + 1 < (int)ft_strlen(e->mapcp[y - 1])
	&& x + 1 < (int)ft_strlen(e->mapcp[y + 1]))
	{
		if (ft_strchr("13", e->mapcp[y - 1][x - 1]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y - 1][x]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y - 1][x + 1]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y][x + 1]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y + 1][x + 1]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y + 1][x]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y + 1][x - 1]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		if (ft_strchr("13", e->mapcp[y][x - 1]) == 0)
			ft_disp_error_msg(e, "Map not closed.\n", NULL);
		return ;
	}
	ft_disp_error_msg(e, "Map not closed.\n", NULL);
}

void			ft_search_walls(t_elem *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (e->mapcp[y])
	{
		while (e->mapcp[y][x])
		{
			if (e->mapcp[y][x] == '3')
				ft_case_search_walls(e, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void			ft_check_valid_map(t_elem *e)
{
	int i;
	int j;

	i = 0;
	j = -1;
	e->p.x = -1;
	ft_map_copy(e);
	ft_map_flood_fill(e);
	ft_free_mapcp(e);
	ft_complete_map_spaces(e);
	while (e->map[++i])
	{
		while (e->map[i][++j])
			ft_check_valid_map_line(e, i, j);
		j = -1;
	}
	if (e->p.x == -1)
		ft_disp_error_msg(e, "Please indicate player position in map.\n", NULL);
	j = 0;
	while (e->map[i - 1][j])
		j++;
	e->msx = j - 1;
}
