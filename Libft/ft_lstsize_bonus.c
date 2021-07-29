/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:43:18 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:54:56 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	nbr;
	t_list			*current;

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
