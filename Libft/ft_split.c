/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:30:12 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:55:36 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_mallocnfill(char const *s, char c)
{
	char			*split;
	unsigned int	mallocsize;
	unsigned int	i;

	mallocsize = 0;
	i = 0;
	while (s[mallocsize] && s[mallocsize] != c)
		mallocsize++;
	if (!(split = (char *)malloc(sizeof(char) * (mallocsize + 1))))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		split[i] = s[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

static unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	countwords;

	countwords = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			countwords++;
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	return (countwords);
}

static int			ft_freeprevmallocs(char **split, long long int i)
{
	while (i)
	{
		free(split[i]);
		i--;
	}
	free(split[i]);
	free(split);
	return (0);
}

char				**ft_split(char const *s, char c)
{
	char			**split;
	long long int	i;

	i = 0;
	if (!s || !(split = malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			if (!(split[i] = ft_mallocnfill(s, c)))
				if (!ft_freeprevmallocs(split, i - 1))
					return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	split[i] = 0;
	return (split);
}
