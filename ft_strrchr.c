/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:26:05 by dpanov            #+#    #+#             */
/*   Updated: 2016/11/30 13:26:05 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	n;
	int		flag;

	i = 0;
	n = 0;
	flag = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			n = i;
			flag = 1;
		}
		i++;
	}
	if (flag != 0)
		return ((char *)&s[n]);
	else
		return (NULL);
}
