/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmodulo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:14:08 by schene            #+#    #+#             */
/*   Updated: 2019/11/28 11:14:10 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	fill_space(int i, int size, char c)
{
	while (i < (size - 1))
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int			ft_putmodulo(va_list *ap, t_flags *param)
{
	int		i;
	int		size;

	size = 1;
	i = 0;
	(void)ap;
	if (param->size != -1)
		size = param->size;
	if (param->side == 0)
		i = fill_space(i, size, param->c);
	ft_putchar('%');
	if (param->side == 1)
		i = fill_space(i, size, ' ');
	return (size);
}
