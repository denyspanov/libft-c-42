/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:25:35 by dpanov            #+#    #+#             */
/*   Updated: 2016/12/10 14:13:54 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntdigits(int n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		i;
	size_t	j;

	j = ft_cntdigits(n);
	if (!(dst = ft_strnew(j)))
		return (NULL);
	if (n == 0)
	{
		dst[0] = 48;
		return (dst);
	}
	if (n < 0)
		dst[0] = '-';
	while (j - 1 > 0)
	{
		i = n % 10;
		if (i < 0)
			i = -i;
		dst[j-- - 1] = i + 48;
		n /= 10;
	}
	if (n > 0)
		dst[0] = n + 48;
	return (dst);
}
