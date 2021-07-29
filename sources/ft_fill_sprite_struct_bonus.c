/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_sprite_struct_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:52:15 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 15:31:15 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

float			ft_mod_pib(float ra)
{
	if (ra >= M_PI / 2)
		ra -= 2 * M_PI;
	if (ra <= -M_PI / 2)
		ra += 2 * M_PI;
	return (ra);
}

static float	ft_mod_pi(float ra, float prec)
{
	if (ra >= prec)
		ra -= prec;
	if (ra < 0)
		ra += prec;
	return (ra);
}

float			ft_find_sprite_angle(t_elem *e, float sx, float sy, float dist)
{
	float	angle;

	if (e->p.x - sx >= 0)
	{
		if (e->p.y - sy >= 0)
			angle = M_PI - acos(((float)e->p.x - sx) / dist);
		else
			angle = M_PI + acos(((float)e->p.x - sx) / dist);
	}
	else
	{
		if (e->p.y - sy >= 0)
			angle = acos((sx - (float)e->p.x) / dist);
		else
			angle = 2 * M_PI - acos((sx - (float)e->p.x) / dist);
	}
	angle = ft_mod_pi(angle, 2 * M_PI);
	return (angle);
}

static t_sprite	*ft_lstspritenew(t_elem *e, float ra, t_sprpos *spr, float an)
{
	t_sprite	*new;

	spr->dist = sqrt(pow(e->p.x - spr->x, 2) + pow(e->p.y - spr->y, 2));
	if (!(new = malloc(sizeof(t_sprite))))
		ft_disp_error_msg(e, "Malloc lst error", NULL);
	new->offset = CUBE_S / 2 + tan(ft_mod_pib(an - ra)) * spr->dist;
	if (spr->life == 0)
		new->dead = 1;
	else
		new->dead = 0;
	new->gridx = spr->x;
	new->gridy = spr->y;
	new->dist = spr->dist;
	new->shoot = spr->shoot;
	new->next = 0;
	return (new);
}

void			ft_fill_sprite_struct(t_elem *e, float ra,
												t_sprpos *sprpos, float angle)
{
	t_sprite	*current;

	current = e->sp;
	if (!current)
		e->sp = ft_lstspritenew(e, ra, sprpos, angle);
	else
	{
		while (current->next)
			current = current->next;
		current->next = ft_lstspritenew(e, ra, sprpos, angle);
	}
}
