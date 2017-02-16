/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:27:36 by dpanov            #+#    #+#             */
/*   Updated: 2016/10/04 18:28:02 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int mnb;

	if (nb < 0)
	{
		ft_putchar('-');
		mnb = -nb;
	}
	else
		mnb = nb;
	if (mnb >= 10)
	{
		ft_putnbr(mnb / 10);
		ft_putnbr(mnb % 10);
	}
	else if (mnb < 10)
	{
		ft_putchar(mnb + '0');
	}
}
