/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:34:38 by dpanov            #+#    #+#             */
/*   Updated: 2016/11/23 14:34:39 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t p;
	size_t l;
	size_t i;

	i = 0;
	p = ft_strlen(s1);
	l = ft_strlen(s2);
	while (i < n && i < l)
	{
		s1[i + p] = s2[i];
		i++;
	}
	s1[i + p] = '\0';
	return (s1);
}
