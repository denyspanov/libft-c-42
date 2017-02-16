/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:25:25 by dpanov            #+#    #+#             */
/*   Updated: 2016/12/10 14:10:55 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntwords(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		n++;
		while (s[i] == c && s[i])
			i++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**buf;
	unsigned int	i;
	size_t			k;
	size_t			t;

	i = 0;
	t = 0;
	if (s == NULL)
		return (NULL);
	if (!(buf = (char **)ft_memalloc(sizeof(char*) * (ft_cntwords(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i] != c))
		{
			k = 0;
			while (s[i + k] != c && s[i + k])
				k++;
			if (!(buf[t++] = ft_strsub(s, i, k)))
				return (NULL);
			i += k - 1;
		}
		i++;
	}
	return (buf);
}
