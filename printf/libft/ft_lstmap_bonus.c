/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:04:20 by epetrill          #+#    #+#             */
/*   Updated: 2020/02/16 00:04:21 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *created;
	t_list *first;
	t_list *previous;

	if (!(lst) || !(created = ft_lstnew(f(lst->content))))
		return (NULL);
	first = created;
	previous = created;
	lst = lst->next;
	while (lst)
	{
		if (!(created = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		previous->next = created;
		previous = created;
		lst = lst->next;
	}
	return (first);
}
