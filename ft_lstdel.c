/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:55:24 by dpanov            #+#    #+#             */
/*   Updated: 2016/12/07 14:55:25 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	tmp = (*alst);
	while (tmp)
	{
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
		tmp = (*alst);
	}
	(*alst) = NULL;
}
