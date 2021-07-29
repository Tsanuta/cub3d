/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:27:38 by olidon            #+#    #+#             */
/*   Updated: 2020/03/03 10:42:25 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int				ft_lstmapsize(t_map *lst)
{
	int		nbr;
	t_map	*current;

	nbr = 0;
	if (lst)
	{
		current = lst;
		while (current)
		{
			nbr++;
			current = current->next;
		}
		return (nbr);
	}
	return (0);
}

void			ft_lstmapclear(t_map **lst)
{
	t_map	*current;
	t_map	*temp;

	current = *lst;
	temp = *lst;
	if (current)
	{
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		*lst = NULL;
	}
}

char			*ft_rmspacedup(t_elem *e, char *line, char *lineb)
{
	char	*str;
	int		i;
	int		msize;

	i = 0;
	msize = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			msize++;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (msize + 1))))
		ft_disp_error_msg(e, "Malloc str error.\n", lineb);
	i = 0;
	msize = -1;
	while (line[i])
	{
		if (line[i] != ' ')
			str[++msize] = line[i];
		i++;
	}
	str[++msize] = '\0';
	return (str);
}

static t_map	*ft_lstmapnew(t_elem *e, void *content)
{
	t_map	*new;

	if (!(new = malloc(sizeof(t_map))))
		ft_disp_error_msg(e, "Malloc lst error.\n", (char *)content);
	new->map = content;
	new->next = 0;
	return (new);
}

void			ft_stock_map_in_lst(t_elem *e, char *line, t_map **lstmap)
{
	t_map	*current;

	if (e->endmap == 1)
		ft_disp_error_msg(e, "Space between maps lines.\n", line);
	e->exmap = 1;
	if (e->exres == 0 || e->t.exno == 0 || e->t.exso == 0 || e->t.exwe == 0
	|| e->t.exea == 0 || e->t.exsp == 0 || e->c.exf == 0 || e->c.exc == 0)
		ft_disp_error_msg(e, "Map description must be in last.\n", line);
	current = *lstmap;
	if (!current)
		*lstmap = ft_lstmapnew(e, ft_rm_half_space(e, line, line));
	else
	{
		while (current->next)
			current = current->next;
		current->next = ft_lstmapnew(e, ft_rm_half_space(e, line, line));
	}
}
