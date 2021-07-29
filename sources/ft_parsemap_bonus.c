/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:36:05 by olidon            #+#    #+#             */
/*   Updated: 2020/03/03 16:00:01 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void		ft_fill_map_with_ones(char *map, char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		map[i] = str[i];
		i++;
	}
	while (i < len)
	{
		map[i] = '1';
		i++;
	}
	map[i] = '\0';
}

void			ft_complete_map_spaces(t_elem *e)
{
	int		i;
	size_t	lenmax;
	char	*newstr;

	i = 0;
	lenmax = ft_strlen(e->map[i]);
	while (e->map[i])
	{
		if (lenmax < ft_strlen(e->map[i]))
			lenmax = ft_strlen(e->map[i]);
		i++;
	}
	i = 0;
	while (e->map[i])
	{
		if (lenmax > ft_strlen(e->map[i]))
		{
			if (!(newstr = malloc(sizeof(char) * (lenmax + 1))))
				ft_disp_error_msg(e, "Malloc error.\n", NULL);
			ft_fill_map_with_ones(newstr, e->map[i], lenmax);
			free(e->map[i]);
			e->map[i] = newstr;
		}
		i++;
	}
}

void			ft_check_valid_map_line(t_elem *e, int i, int j)
{
	if (ft_strchr("012ENWS", e->map[i][j]) == NULL)
		ft_disp_error_msg(e, "Map's content invalid character.\n", NULL);
	if (ft_strchr("ENWS", e->map[i][j]) != NULL)
	{
		if (e->exp == 1)
			ft_disp_error_msg(e, "Multiple player start position.\n", NULL);
		e->exp = 1;
		ft_fill_player_pos(e, i, j);
	}
	if (ft_strchr("2", e->map[i][j]) != NULL)
		ft_fill_sprite_pos_struct(e, i, j);
}

static void		ft_parse_trimed_line(t_elem *e, char *line, t_map **lstmap)
{
	char	*lcp;

	lcp = NULL;
	lcp = ft_strtrim(line, " ");
	if (line && line[0] != '\0' && lcp && lcp[0] == '\0' && !(e->t.exno == 1
	&& e->t.exso == 1 && e->t.exwe == 1 && e->t.exea == 1 && e->t.exsp == 1
	&& e->exres == 1 && e->c.exc == 1 && e->c.exf == 1))
	{
		free(line);
		line = NULL;
		ft_disp_error_msg(e, "Spaces in empty lines.\n", lcp);
	}
	if (line && line[0] == '\0' && e->exmap == 1)
		e->endmap = 1;
	if (line[0] && ft_strchr("210NSEW ", line[0]) && e->t.exno == 1
	&& e->t.exso == 1 && e->t.exwe == 1 && e->t.exea == 1 && e->t.exsp == 1
	&& e->exres == 1 && e->c.exc == 1 && e->c.exf == 1)
		ft_stock_map_in_lst(e, line, &(*lstmap));
	else if (lcp[0] && (ft_strchr("RNSWEFC", lcp[0]) != NULL))
		ft_parse_elema(lcp, e);
	else if (lcp[0] && lcp[0] != '\0')
		ft_disp_error_msg(e, "Wrong info in map.cub file.\n", lcp);
	free(lcp);
	lcp = NULL;
}

void			ft_parse_file(char *path, t_elem *elem)
{
	int		fd;
	int		get;
	char	*line;
	t_map	*lstmap;

	line = NULL;
	lstmap = NULL;
	get = 1;
	if ((fd = open(path, O_RDONLY)) < 0)
		ft_disp_error_msg(elem, "Can't open .cub file.\n", NULL);
	while (get != 0)
	{
		if ((get = get_next_line(fd, &line)) == -1)
			ft_disp_error_msg(elem, "Invalid fd.\n", NULL);
		ft_parse_trimed_line(elem, line, &lstmap);
		free(line);
		line = NULL;
	}
	if (close(fd) != 0)
		ft_disp_error_msg(elem, "Failing to close map file.\n", NULL);
	ft_lst_to_ptr(&lstmap, elem);
	ft_lstmapclear(&lstmap);
	ft_check_valid_map(elem);
}
