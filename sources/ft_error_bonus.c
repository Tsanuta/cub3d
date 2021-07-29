/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:08:05 by olidon            #+#    #+#             */
/*   Updated: 2020/03/03 15:36:10 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void		ft_disp_error_msg(t_elem *e, char *msg, char *line)
{
	int	i;

	i = -1;
	if (line)
		free(line);
	write(1, "Error\n", 6);
	write(1, &msg[0], ft_strlen(msg));
	if (e)
	{
		if (e->mapcp)
		{
			while (e->mapcp[++i])
				free(e->mapcp[i]);
		}
		if (e->mapcp)
			free(e->mapcp);
		ft_free_struct_elem(e);
	}
	else
		exit(EXIT_SUCCESS);
}

static void	ft_free_img_if_exist(t_elem *e, t_img *ptr)
{
	if (ptr)
		mlx_destroy_image(e->m_ptr, ptr);
}

static void	ft_free_img(t_elem *elem)
{
	ft_free_img_if_exist(elem, elem->cimg.ptr);
	ft_free_img_if_exist(elem, elem->mimg.ptr);
	ft_free_img_if_exist(elem, elem->t.no.ptr);
	ft_free_img_if_exist(elem, elem->t.ea.ptr);
	ft_free_img_if_exist(elem, elem->t.so.ptr);
	ft_free_img_if_exist(elem, elem->t.we.ptr);
	ft_free_img_if_exist(elem, elem->t.s.ptr);
	ft_free_img_if_exist(elem, elem->t.s1.ptr);
	ft_free_img_if_exist(elem, elem->t.s2.ptr);
	ft_free_img_if_exist(elem, elem->t.s3.ptr);
	ft_free_img_if_exist(elem, elem->t.w1sc.ptr);
	ft_free_img_if_exist(elem, elem->t.w2sc.ptr);
	ft_free_img_if_exist(elem, elem->t.pointsc.ptr);
	ft_free_img_if_exist(elem, elem->t.lifesc.ptr);
	ft_free_img_if_exist(elem, elem->t.deadsc.ptr);
	if (elem->w_ptr)
		mlx_destroy_window(elem->m_ptr, elem->w_ptr);
}

static void	ft_free_sprpos(t_elem *elem, t_sprpos **lst)
{
	t_sprpos	*current;
	t_sprpos	*temp;

	if (elem->bmp)
		free(elem->bmp);
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*lst = NULL;
	ft_free_img(elem);
	if (elem->m_ptr)
		mlx_free_ptr(elem->m_ptr);
	if (elem)
		free(elem);
}

void		ft_free_struct_elem(t_elem *elem)
{
	int		i;

	i = -1;
	if (elem->map)
	{
		while (elem->map[++i])
			free(elem->map[i]);
	}
	if (elem->map)
		free(elem->map);
	if (elem->t.nop)
		free(elem->t.nop);
	if (elem->t.sop)
		free(elem->t.sop);
	if (elem->t.wep)
		free(elem->t.wep);
	if (elem->t.eap)
		free(elem->t.eap);
	if (elem->t.sp)
		free(elem->t.sp);
	ft_free_sprites(&elem->sp);
	ft_free_sprpos(elem, &elem->sprpos);
	exit(EXIT_SUCCESS);
}
