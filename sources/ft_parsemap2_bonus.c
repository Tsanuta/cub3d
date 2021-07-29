/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:24:03 by olidon            #+#    #+#             */
/*   Updated: 2020/03/03 14:58:54 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int		ft_check_separator(t_elem *e, char *linecp,
												char *linecpb, char *lineb)
{
	int	i;

	i = 0;
	if ((linecp[i] < '0' && linecp[i] > '9') || linecp[i] == ',')
		ft_disp_error_msg(e, "No color numbers.\n", lineb);
	while (linecp[i] && linecp[i] >= '0' && linecp[i] <= '9')
		i++;
	if (linecp[i] == ',')
		i++;
	else
	{
		free(linecpb);
		ft_disp_error_msg(e, "Invalid color separator.\n", lineb);
	}
	return (i);
}

unsigned int	ft_fill_color(t_elem *e, char *line, char *lineb)
{
	char			*linecp;
	unsigned int	i;
	int				j;
	int				str[3];

	i = 0;
	j = 0;
	linecp = ft_rmspacedup(e, line, lineb);
	str[j] = ft_atoi(&linecp[i]);
	i += ft_check_separator(e, linecp, linecp, lineb);
	str[++j] = ft_atoi(&linecp[i]);
	i += ft_check_separator(e, &linecp[i], linecp, lineb);
	str[++j] = ft_atoi(&linecp[i]);
	if ((linecp[i] < '0' && linecp[i] > '9') || linecp[i] == '\0')
		ft_disp_error_msg(e, "No color numbers.\n", lineb);
	while (linecp[i])
	{
		if (linecp[i] && (linecp[i] < '0' || linecp[i] > '9'))
		{
			free(linecp);
			ft_disp_error_msg(e, "Ivalid color syntax.\n", lineb);
		}
		i++;
	}
	return (ft_check_color_range(e, linecp, lineb, str));
}

static void		ft_parse_elemc(char *line, t_elem *e, int i)
{
	if (line[i] && line[i] == 'S' && line[i + 1] && line[i + 1] == ' ')
	{
		if (e->t.exsp == 1)
			ft_disp_error_msg(e, "To many lines for S texture path.\n", line);
		e->t.exsp = 1;
		e->t.sp = ft_fill_path(e, &line[i], line);
	}
	if (line[i] && line[i] == 'F' && line[i + 1] && line[i + 1] == ' ')
	{
		if (e->c.exf == 1)
			ft_disp_error_msg(e, "To many lines for F color path.\n", line);
		e->c.exf = 1;
		e->c.f = ft_fill_color(e, &line[i + 1], line);
	}
	if (line[i] && line[i] == 'C' && line[i + 1] && line[i + 1] == ' ')
	{
		if (e->c.exc == 1)
			ft_disp_error_msg(e, "To many lines for C color path.\n", line);
		e->c.exc = 1;
		e->c.c = ft_fill_color(e, &line[i + 1], line);
	}
}

static void		ft_parse_elemb(char *line, t_elem *e, int i)
{
	if (line[i] && line[i + 1] && line[i] == 'S' && line[i + 1] == 'O'
	&& line[i + 2] && line[i + 2] == ' ')
	{
		if (e->t.exso == 1)
			ft_disp_error_msg(e, "To many lines for SO texture path.\n", line);
		e->t.exso = 1;
		e->t.sop = ft_fill_path(e, &line[i], line);
	}
	if (line[i] && line[i + 1] && line[i] == 'W' && line[i + 1] == 'E'
	&& line[i + 2] && line[i + 2] == ' ')
	{
		if (e->t.exwe == 1)
			ft_disp_error_msg(e, "To many lines for WE texture path.\n", line);
		e->t.exwe = 1;
		e->t.wep = ft_fill_path(e, &line[i], line);
	}
	if (line[i] && line[i + 1] && line[i] == 'E' && line[i + 1] == 'A'
	&& line[i + 2] && line[i + 2] == ' ')
	{
		if (e->t.exea == 1)
			ft_disp_error_msg(e, "To many lines for EA texture path.\n", line);
		e->t.exea = 1;
		e->t.eap = ft_fill_path(e, &line[i], line);
	}
}

void			ft_parse_elema(char *line, t_elem *e)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] == 'R' && line[i + 1] && line[i + 1] == ' ')
		ft_fill_res(e, &line[i], line);
	if (line[i] && line[i + 1] && line[i] == 'N' && line[i + 1] == 'O'
	&& line[i + 2] && line[i + 2] == ' ')
	{
		if (e->t.exno == 1)
			ft_disp_error_msg(e, "To many lines for NO texture path.\n", line);
		e->t.exno = 1;
		e->t.nop = ft_fill_path(e, &line[i], line);
	}
	ft_parse_elemb(line, e, i);
	ft_parse_elemc(line, e, i);
}
