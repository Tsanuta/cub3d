/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:42:39 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:56:48 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_start(char const *s1, char const *set)
{
	unsigned int	i;
	long long int	j;

	i = 0;
	j = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static unsigned int	ft_len(char const *s1, char const *set)
{
	unsigned int	s1len;
	unsigned int	i;
	long long int	j;

	i = 0;
	j = 0;
	s1len = ft_strlen(s1);
	while (set[j] && s1len > 0)
	{
		if ((s1len - 1 - i) && s1[s1len - 1 - i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (s1len - i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	unsigned int	start;
	unsigned int	len;

	if (!s1 || (!s1 && !set))
		return (ft_strdup(""));
	else if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	len = ft_len(s1, set);
	if (!(trim = ft_substr(s1, start, len - start)))
		return (NULL);
	return (trim);
}
