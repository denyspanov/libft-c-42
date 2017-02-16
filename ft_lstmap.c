/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:56:14 by dpanov            #+#    #+#             */
/*   Updated: 2016/12/07 14:56:15 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;

	head = NULL;
	if (!lst || !f)
		return (head);
	head = f(lst);
	new = head;
	lst = lst->next;
	while (lst)
	{
		new->next = (*f)(lst);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
