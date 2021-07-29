/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:13:40 by olidon            #+#    #+#             */
/*   Updated: 2020/02/13 17:54:46 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*lstzero;
	t_list	*newlst;

	if (!lst)
		return (NULL);
	current = lst;
	if (!(lstzero = malloc(sizeof(t_list))))
		return (NULL);
	lstzero->content = f(current->content);
	lstzero->next = NULL;
	current = current->next;
	while (current)
	{
		if (!(newlst = malloc(sizeof(t_list))))
			ft_lstclear(&lstzero, &(*del));
		newlst->content = f(current->content);
		newlst->next = NULL;
		ft_lstadd_back(&lstzero, newlst);
		current = current->next;
	}
	return (lstzero);
}
