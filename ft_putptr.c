/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:51:11 by schene            #+#    #+#             */
/*   Updated: 2019/11/13 16:13:10 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void const *ptr)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;

	adr = (unsigned long)ptr;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putstr("0x");
	while (i < 9)
	{
		ft_putchar(res[i]);
		i++;
	}
}
