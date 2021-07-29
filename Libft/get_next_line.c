/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:09:03 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:57:10 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bufrest(char *buf, int del)
{
	size_t	i;
	char	*rest;

	i = 0;
	if (buf)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				if (!(rest = ft_strjoinfree(&buf[i], NULL, 0)))
					return (NULL);
				if (del != 0)
					free(buf);
				return (rest);
			}
			i++;
		}
		if (del != 0)
			free(buf);
	}
	if (!(rest = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	rest[0] = '\0';
	return (rest);
}

int		ft_readline(t_gnl **lstzero, t_gnl **lst, char **line, char *buf)
{
	long long		ret;

	if (!(*line = ft_strjoinfree(*line, (*lst)->rest, 1))
				|| !((*lst)->rest = ft_bufrest((*lst)->rest, 1)))
		return (-1);
	if ((*lst)->rest && (*lst)->rest[0])
	{
		(*lst)->rest = ft_move((*lst)->rest, &buf);
		return (1);
	}
	while ((ret = read((*lst)->fd, buf, BUFFER_SIZEGNL)))
	{
		buf[ret] = '\0';
		free((*lst)->rest);
		if (!(*line = ft_strjoinfree(*line, buf, 1))
				|| !((*lst)->rest = ft_bufrest(buf, 0)))
			return (-1);
		if ((*lst)->rest[0])
		{
			(*lst)->rest = ft_move((*lst)->rest, &buf);
			return (1);
		}
	}
	ft_freelst(&(*lstzero), &(*lst), &buf);
	return (0);
}

void	ft_freelst(t_gnl **lstzero, t_gnl **lst, char **buf)
{
	t_gnl *current;
	t_gnl *newlst;

	free(*buf);
	current = *lstzero;
	while (current)
	{
		if (current == *lst)
		{
			newlst = current->next;
			current = *lstzero;
			if (*lst == *lstzero)
				*lstzero = newlst;
			while (current && current->next)
			{
				if (current->next == *lst)
					current->next = newlst;
				current = current->next;
			}
			free((*lst)->rest);
			free(*lst);
			return ;
		}
		current = current->next;
	}
}

t_gnl	*ft_searchlst(t_gnl **lst, int fd)
{
	t_gnl	*current;
	t_gnl	*new;

	current = *lst;
	if (current)
	{
		while (current)
		{
			if (current->fd == fd)
				return (current);
			current = current->next;
		}
	}
	new = ft_lstnewgnl(fd);
	current = *lst;
	if (!current)
	{
		*lst = new;
		return (*lst);
	}
	while (current->next)
		current = current->next;
	current->next = new;
	return (current->next);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lstzero;
	t_gnl			*currentlst;
	char			*buf;
	int				get;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZEGNL + 1))))
		return (-1);
	buf[0] = '\0';
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFFER_SIZEGNL < 1)
		return (ft_freeall(&buf, &lstzero));
	if (!(*line = ft_strjoinfree(NULL, NULL, 0)))
		return (ft_freeall(&buf, &lstzero));
	if (!(currentlst = ft_searchlst(&lstzero, fd)))
		return (ft_freeall(&buf, &lstzero));
	get = ft_readline(&lstzero, &currentlst, &*line, buf);
	if (get == -1)
		return (ft_freeall(&buf, &lstzero));
	else
		return (get);
}
