/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:00:06 by schene            #+#    #+#             */
/*   Updated: 2019/11/21 12:05:02 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*ft_s_nb(int long nb, int precision)
{
	char	*s_nb;

	if (nb == 0 && precision == 0)
		s_nb = ft_strdup("\0");
	else
		s_nb = ft_itoa(nb);
	return (s_nb);
}

int			ft_fill_right(char c, int i, int p, int sz)
{
	if (i && c == '0')
		ft_putchar('-');
	while ((sz - i) > p)
	{
		ft_putchar(c);
		sz--;
	}
	return (sz);
}

int			ft_fill_middle(char *s_nb, char c, int sz, int p)
{
	if (check_minus(s_nb) && c == ' ' && sz--)
		ft_putchar('-');
	while (p > ((int)ft_strlen(s_nb) - check_minus(s_nb)) && p--)
		ft_putchar('0');
	return (sz);
}

int			check_minus(char *s_nb)
{
	if (s_nb[0] == '-')
		return (1);
	return (0);
}

int			ft_putnbr_pf(va_list *ap, t_flags *param)
{
	int long	nb;
	char		*s_nb;
	int			sz;
	int			p;
	int			rtn;

	rtn = 0;
	nb = va_arg(*ap, int);
	s_nb = ft_s_nb(nb, param->precision);
	sz = param->size;
	p = find_p((int)ft_strlen(s_nb), param->precision, check_minus(s_nb));
	if (sz < p)
		sz = p;
	rtn = sz;
	if (check_minus(s_nb) && (param->size == -1 ||
		(param->size == param->precision && param->size != -1)))
		rtn++;
	if (param->precision != -1)
		param->c = ' ';
	if (param->side == 0)
		sz = ft_fill_right(param->c, check_minus(s_nb), p, sz);
	sz = ft_fill_middle(s_nb, param->c, sz, p);
	ft_fill_left(param->side, sz, p, &s_nb[check_minus(s_nb)]);
	free(s_nb);
	return (rtn);
}
