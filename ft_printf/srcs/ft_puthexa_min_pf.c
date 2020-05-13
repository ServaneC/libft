/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_min_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:59:57 by schene            #+#    #+#             */
/*   Updated: 2019/11/21 12:04:31 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*ft_fill_s_nb(unsigned int nb)
{
	char const		*base;
	int				i;
	int				j;
	char			result[9];
	char			*s_nb;

	base = "0123456789abcdef";
	i = 0;
	j = -1;
	while (nb > 0)
	{
		result[i++] = base[nb % 16];
		nb = nb / 16;
	}
	if (!(s_nb = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (i > 0)
		s_nb[++j] = result[--i];
	s_nb[++j] = '\0';
	return (s_nb);
}

static char	*hexa_to_str(unsigned int nb, int precision)
{
	char			*s_nb;

	if (nb == 0)
	{
		if (precision == 0)
		{
			s_nb = ft_strdup("\0");
			return (s_nb);
		}
		if (!(s_nb = malloc(sizeof(char) * 2)))
			return (NULL);
		s_nb[0] = '0';
		s_nb[1] = '\0';
	}
	else
		s_nb = ft_fill_s_nb(nb);
	return (s_nb);
}

static int	ft_fill(int side, int sz, int p, char c)
{
	if (side == 0)
	{
		while (sz > p)
		{
			ft_putchar(c);
			sz--;
		}
	}
	if (side == 1)
	{
		while (sz > p)
		{
			ft_putchar(' ');
			sz--;
		}
	}
	return (sz);
}

int			find_p(int len, int precision, int i)
{
	int	p;

	p = precision;
	if (p < (len - i))
		p = (len - i);
	return (p);
}

int			ft_puthexa_min_pf(va_list *ap, t_flags *param)
{
	unsigned int	nb;
	char			*s_nb;
	int				sz;
	int				p;
	int				rtn;

	nb = va_arg(*ap, unsigned int);
	s_nb = hexa_to_str(nb, param->precision);
	p = find_p((int)ft_strlen(s_nb), param->precision, 0);
	sz = param->size;
	if (sz < p)
		sz = p;
	rtn = sz;
	if (param->precision != -1)
		param->c = ' ';
	if (param->side == 0)
		sz = ft_fill(param->side, sz, p, param->c);
	nb = p;
	while ((int)nb > (int)ft_strlen(s_nb) && nb--)
		ft_putchar('0');
	ft_putstr(s_nb);
	ft_fill(param->side, sz, p, param->c);
	free(s_nb);
	return (rtn);
}
