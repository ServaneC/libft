/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:00:16 by schene            #+#    #+#             */
/*   Updated: 2019/11/21 12:05:26 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ptr_zero(int size, int side)
{
	int	i;

	if (size < 3)
		size = 3;
	i = size;
	if (side == 0)
	{
		while (i > 3 && --i)
			ft_putchar(' ');
	}
	ft_putstr("0x0");
	if (side == 1)
	{
		while (i > 3 && --i)
			ft_putchar(' ');
	}
	return (size);
}

static void	fill_space(int nb, int len)
{
	while (nb > len && --nb)
		ft_putchar(' ');
}

static char	*fill_str(int i, char result[15])
{
	char	*s_nb;
	int		j;

	if (!(s_nb = malloc(sizeof(char) * i + 1)))
		return (NULL);
	s_nb[0] = '0';
	s_nb[1] = 'x';
	j = 1;
	while (i > 0)
		s_nb[++j] = result[--i];
	s_nb[++j] = '\0';
	return (s_nb);
}

static void	print_adress(int side, int i, char *s_nb)
{
	if (side == 0)
		fill_space(i, (int)ft_strlen(s_nb));
	ft_putstr(s_nb);
	if (side == 1)
		fill_space(i, (int)ft_strlen(s_nb));
}

int			ft_putptr_pf(va_list *ap, t_flags *param)
{
	char const		*base;
	int				i;
	char			result[15];
	unsigned long	nb;
	char			*s_nb;

	nb = (unsigned long)va_arg(*ap, void *);
	base = "0123456789abcdef";
	if (nb == 0)
		return (ptr_zero(param->size, param->side));
	i = 0;
	while (nb > 0)
	{
		result[i++] = base[nb % 16];
		nb = nb / 16;
	}
	s_nb = fill_str(i, result);
	if ((i = param->size) < ((int)ft_strlen(s_nb)))
		i = ((int)ft_strlen(s_nb));
	print_adress(param->side, i, s_nb);
	free(s_nb);
	return (i);
}
