/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:22:48 by dpanov            #+#    #+#             */
/*   Updated: 2016/11/30 13:22:49 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j] && (i + 1) < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	if (!j)
		i = size;
	while (src[j++])
		i++;
	return (i);
}
