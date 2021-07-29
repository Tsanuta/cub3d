/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:18:03 by olidon            #+#    #+#             */
/*   Updated: 2020/02/29 15:20:00 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_parse_valuesa(t_elem *e)
{
	e->t.exno = 0;
	e->t.exso = 0;
	e->t.exwe = 0;
	e->t.exea = 0;
	e->t.exsp = 0;
	e->exres = 0;
	e->exmap = 0;
	e->endmap = 0;
	e->exp = 0;
	e->c.exc = 0;
	e->c.exf = 0;
	e->save = 0;
	e->map = NULL;
	e->mapcp = NULL;
	e->t.nop = NULL;
	e->t.sop = NULL;
	e->t.wep = NULL;
	e->t.eap = NULL;
	e->t.sp = NULL;
	e->sp = NULL;
}

static void	ft_init_parse_valuesb(t_elem *e)
{
	e->sprpos = NULL;
	e->bmp = NULL;
	e->cimg.ptr = NULL;
	e->mimg.ptr = NULL;
	e->t.no.ptr = NULL;
	e->t.ea.ptr = NULL;
	e->t.so.ptr = NULL;
	e->t.we.ptr = NULL;
	e->t.s.ptr = NULL;
	e->w_ptr = NULL;
	e->m_ptr = NULL;
}

int			main(int ac, char **av)
{
	t_elem		*elem;

	elem = NULL;
	if (!(elem = malloc(sizeof(t_elem))))
		ft_disp_error_msg(elem, "Malloc struct elem error\n", NULL);
	ft_init_parse_valuesa(elem);
	ft_init_parse_valuesb(elem);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == 0)
			elem->save = 1;
		else
			ft_disp_error_msg(elem, "No valid arguments with exe\n", NULL);
	}
	if (ac < 2 || ft_strrncmp(av[1], ".cub", 3) || ac > 3)
		ft_disp_error_msg(elem, "No valid arguments with executable\n", NULL);
	ft_parse_file(av[1], elem);
	ft_display(elem);
	ft_free_struct_elem(elem);
	return (0);
}
