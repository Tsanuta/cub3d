/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap7_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:26:12 by olidon            #+#    #+#             */
/*   Updated: 2020/03/03 11:57:15 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static char	*ft_rm_half_spaceb(t_elem *e, char *line, char *lineb, int msize)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (msize + 1))))
		ft_disp_error_msg(e, "Malloc str error.\n", lineb);
	i = 0;
	msize = -1;
	while (line[i])
	{
		if (line[i] == ' ')
			str[++msize] = '0';
		else
			str[++msize] = line[i];
		if (line[i + 1] == ' ' && line[i + 2] != '\0')
			i += 2;
		else if (line[i + 1] == '\0')
			i++;
	}
	str[++msize] = '\0';
	return (str);
}

char		*ft_rm_half_space(t_elem *e, char *line, char *lineb)
{
	int		i;
	int		msize;

	i = 0;
	msize = 0;
	while (line[i])
	{
		if (line[i + 1] == ' ' && line[i + 2] != '\0')
		{
			i += 2;
			msize++;
		}
		else if (line[i + 1] == '\0')
		{
			i++;
			msize++;
		}
		else
			ft_disp_error_msg(e, "No spaces beetween map chars.\n", lineb);
	}
	return (ft_rm_half_spaceb(e, line, lineb, msize));
}

void		ft_map_flood_fill(t_elem *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (e->mapcp[y])
	{
		while (e->mapcp[y][x])
		{
			if (ft_strchr("NSEW", e->mapcp[y][x]) != 0)
			{
				ft_case_flood_fill(e, x, y);
				ft_search_walls(e);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void		ft_map_copy(t_elem *e)
{
	int	i;

	i = 0;
	if (!(e->mapcp = malloc(sizeof(char *) * (e->msy + 2))))
		ft_disp_error_msg(e, "Mapcp malloc.\n", NULL);
	e->mapcp[e->msy + 1] = 0;
	while (e->map[i])
	{
		e->mapcp[i] = ft_strdup(e->map[i]);
		i++;
	}
}

void		ft_free_mapcp(t_elem *e)
{
	int	i;

	i = -1;
	while (e->mapcp[++i])
		free(e->mapcp[i]);
	free(e->mapcp);
	e->mapcp = NULL;
}
