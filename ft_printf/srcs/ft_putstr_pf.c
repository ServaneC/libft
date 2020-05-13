/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:00:23 by schene            #+#    #+#             */
/*   Updated: 2019/11/21 12:05:52 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	right_side(int size, int len, char *str)
{
	while (size-- > len)
		ft_putchar(' ');
	size = 0;
	while (len--)
		ft_putchar(str[size++]);
}

int			ft_putstr_pf(va_list *ap, t_flags *param)
{
	char	*str;
	int		len;
	int		size;
	int		i;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	if (param->precision < len && (param->precision != -1))
		len = param->precision;
	if ((size = param->size) == -1 || size < len)
		size = len;
	if (param->side == 0)
		right_side(size, len, str);
	else if (param->side == 1)
	{
		while (i < len)
			ft_putchar(str[i++]);
		while (len++ < size)
			ft_putchar(' ');
	}
	return (size);
}
