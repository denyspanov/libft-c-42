/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:35:20 by dpanov            #+#    #+#             */
/*   Updated: 2016/12/07 14:41:18 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char*string;
	int len;

	len = 1;
	while (src[len])
	{
		len++;
	}
	string = (char*)malloc(len + 1);
	if (string == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (src[len])
	{
		string[len] = src[len];
		len++;
	}
	string[len] = '\0';
	return (string);
}
