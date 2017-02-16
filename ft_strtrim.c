/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:25:08 by dpanov            #+#    #+#             */
/*   Updated: 2016/12/07 14:25:09 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_ch(const char *s)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			n++;
			i++;
		}
		else
			break ;
	}
	return (n);
}

static int	last_ch(const char *s)
{
	int i;
	int n;

	if ((n = (int)ft_strlen(s)) == 0)
		return (n);
	i = n - 1;
	while (i > 0)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i--;
		else
			return (i);
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	int		j;
	char	*str;

	if (!(s))
		return (NULL);
	n = last_ch(s) - first_ch(s) + 1;
	if (!(str = ft_strnew(n)))
		return (NULL);
	i = first_ch(s);
	j = 0;
	while (s[i] && i <= last_ch(s))
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
