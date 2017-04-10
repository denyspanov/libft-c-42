/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:24:34 by dpanov            #+#    #+#             */
/*   Updated: 2016/11/27 11:24:34 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t bytes;

	bytes = 0;
	while (bytes < n)
	{
		*((unsigned char *)dst + bytes) = *((unsigned char *)src + bytes);
		if (*((unsigned char *)src + bytes) == (unsigned char)c)
			return ((unsigned char *)dst + bytes + 1);
		bytes++;
	}
	return (NULL);
}
