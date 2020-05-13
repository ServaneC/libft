/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_pf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:59:25 by schene            #+#    #+#             */
/*   Updated: 2019/11/21 12:02:21 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*str_from_nb(unsigned long nb, int precision)
{
	char			*s_nb;
	int				result[12];
	int				i;
	int				j;

	i = 0;
	j = -1;
	if (nb == 0 && precision == 0)
		s_nb = ft_strdup("\0");
	else if (nb == 0)
		s_nb = ft_strdup("0\0");
	else
	{
		while (nb > 0)
		{
			result[i++] = nb % 10;
			nb /= 10;
		}
		if (!(s_nb = malloc(sizeof(char) * i + 1)))
			return (NULL);
		while (i >= 1)
			s_nb[++j] = (result[--i] + '0');
	}
	return (s_nb);
}

void		ft_fill_left(int side, int sz, int p, char *s_nb)
{
	ft_putstr(s_nb);
	if (side == 1)
	{
		while (sz > p)
		{
			ft_putchar(' ');
			sz--;
		}
	}
}

int			ft_put_unsigned_nbr_pf(va_list *ap, t_flags *param)
{
	unsigned long	nb;
	char			*s_nb;
	int				sz;
	int				p;
	int				rtn;

	nb = va_arg(*ap, unsigned int);
	s_nb = str_from_nb(nb, param->precision);
	sz = param->size;
	p = param->precision;
	if (p < (int)ft_strlen(s_nb))
		p = (int)ft_strlen(s_nb);
	if (sz < p)
		sz = p;
	rtn = sz;
	if (param->precision != -1)
		param->c = ' ';
	if (param->side == 0)
		ft_fill_right(param->c, 0, p, sz);
	sz = ft_fill_middle(s_nb, param->c, sz, p);
	ft_fill_left(param->side, sz, p, s_nb);
	free(s_nb);
	return (rtn);
}
