/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:59:38 by schene            #+#    #+#             */
/*   Updated: 2019/11/21 12:03:12 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	fill_space(int i, int size)
{
	while (i < (size - 1))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			ft_putchar_pf(va_list *ap, t_flags *param)
{
	char	c;
	int		i;
	int		size;

	size = 1;
	i = 0;
	c = (va_arg(*ap, int));
	if (param->size != -1)
		size = param->size;
	if (param->side == 0)
		i = fill_space(i, size);
	ft_putchar(c);
	if (param->side == 1)
		i = fill_space(i, size);
	return (size);
}
