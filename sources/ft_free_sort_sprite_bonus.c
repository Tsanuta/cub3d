/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sort_sprite_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:20:19 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:47:31 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_swap_float(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_sort_sprites(t_sprite **sp)
{
	t_sprite	*current;

	current = *sp;
	while (current->next)
	{
		if (current->dist < current->next->dist)
		{
			ft_swap_int(&current->offset, &current->next->offset);
			ft_swap_int(&current->gridx, &current->next->gridx);
			ft_swap_int(&current->gridy, &current->next->gridy);
			ft_swap_int(&current->dead, &current->next->dead);
			ft_swap_int(&current->shoot, &current->next->shoot);
			ft_swap_float(&current->dist, &current->next->dist);
			current = *sp;
		}
		else
			current = current->next;
	}
}

void		ft_free_sprites(t_sprite **lst)
{
	t_sprite	*current;
	t_sprite	*temp;

	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*lst = NULL;
}
