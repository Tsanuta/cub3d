/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:04:28 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 13:44:04 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_sprpos	*ft_spriteposnew(t_elem *e, int x, int y)
{
	t_sprpos	*new;

	if (!(new = malloc(sizeof(t_sprpos))))
		ft_disp_error_msg(e, "Malloc lst.\n", NULL);
	new->x = x * CUBE_S + CUBE_S / 2;
	new->ox = x * CUBE_S + CUBE_S / 2;
	new->y = y * CUBE_S + CUBE_S / 2;
	new->oy = y * CUBE_S + CUBE_S / 2;
	new->vis = 0;
	new->next = NULL;
	return (new);
}

void			ft_fill_sprite_pos_struct(t_elem *e, int i, int j)
{
	t_sprpos	*current;

	current = e->sprpos;
	if (!current)
		e->sprpos = ft_spriteposnew(e, j, i);
	else
	{
		while (current->next)
			current = current->next;
		current->next = ft_spriteposnew(e, j, i);
	}
}

void			ft_lst_to_ptr(t_map **lstmap, t_elem *e)
{
	int		msize;
	t_map	*current;

	current = *lstmap;
	msize = 0;
	msize = ft_lstmapsize(*lstmap);
	if ((e->msy = msize - 1) < 2)
		ft_disp_error_msg(e, "Not enough lines in map.\n", NULL);
	if (!(e->map = malloc(sizeof(char *) * (msize + 1))))
		ft_disp_error_msg(e, "Malloc for map.\n", NULL);
	msize = 0;
	while (current)
	{
		e->map[msize] = current->map;
		current = current->next;
		msize++;
	}
	e->map[msize] = 0;
}
