/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:11:55 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:54:31 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	temp = *lst;
	if (current)
	{
		while (current)
		{
			del(current->content);
			temp = current->next;
			free(current);
			current = temp;
		}
		*lst = NULL;
	}
}
