/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:23:13 by dpanov            #+#    #+#             */
/*   Updated: 2016/11/30 13:23:14 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (little[j] && big[i + j] && (big[i + j] == little[j]) &&
				(i + j) < len)
		{
			if (j == (ft_strlen(little) - 1))
				return ((char *)&big[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
