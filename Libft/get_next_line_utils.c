/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:06:53 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:57:06 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstnewgnl(int fd)
{
	t_gnl	*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	if (!(new->rest = ft_strjoinfree(NULL, NULL, 0)))
		return (NULL);
	new->next = NULL;
	return (new);
}

char	*ft_strjoinfree(char *s1, char *s2, int del)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!(str = (char *)malloc(sizeof(char) *
					(ft_strlenplus(s1, del) + ft_strlenplus(s2, del) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (del == 1)
		free(s1);
	s1 = NULL;
	while (s2 && s2[j] && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlenplus(char *s, int stopn)
{
	unsigned int i;

	i = 0;
	if (!s)
		return (0);
	if (stopn == 1)
		while (s[i] && s[i] != '\n')
			i++;
	else
		while (s[i])
			i++;
	return (i);
}

char	*ft_move(char *str, char **buf)
{
	int i;

	i = 0;
	free(*buf);
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_freeall(char **buf, t_gnl **lst)
{
	t_gnl	*current;
	t_gnl	*temp;

	current = NULL;
	free(*buf);
	if (*lst)
	{
		current = *lst;
		while (current)
		{
			free(current->rest);
			temp = current->next;
			free(current);
			current = temp;
		}
		*lst = NULL;
	}
	return (-1);
}
