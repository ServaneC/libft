/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:37:26 by schene            #+#    #+#             */
/*   Updated: 2019/11/19 10:53:32 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*fill_tabs(int (*tab_f[10]) (va_list *, t_flags *))
{
	char	*tab_idx;

	tab_idx = "cspdiuxX%";
	tab_f[0] = &ft_putchar_pf;
	tab_f[1] = &ft_putstr_pf;
	tab_f[2] = &ft_putptr_pf;
	tab_f[3] = &ft_putnbr_pf;
	tab_f[4] = &ft_putnbr_pf;
	tab_f[5] = &ft_put_unsigned_nbr_pf;
	tab_f[6] = &ft_puthexa_min_pf;
	tab_f[7] = &ft_puthexa_maj_pf;
	tab_f[8] = &ft_putmodulo;
	return (tab_idx);
}

int			search_index(char c, char tab_idx[10])
{
	int	i;

	i = 0;
	while (tab_idx[i])
	{
		if (tab_idx[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || ft_isdigit((int)c))
		return (1);
	return (0);
}

int			check_valid(char *str, char *tab_idx)
{
	int	i;

	i = 0;
	while (is_flag(str[i]))
		i++;
	if ((search_index(str[i], tab_idx)) != -1)
		return (1);
	else
		return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		(*tab_f[10])(va_list *, t_flags *);
	char	*tab_idx;
	int		i;
	int		rtn;

	i = -1;
	rtn = 0;
	va_start(ap, format);
	tab_idx = fill_tabs(tab_f);
	while (format[++i])
	{
		if (format[i] == '%' && check_valid((char *)&format[++i], tab_idx))
		{
			rtn += print_result((char *)&format[i], tab_f, tab_idx, &ap);
			while (search_index(format[i], tab_idx) == -1)
				i++;
		}
		else if (format[i] != '%' && ++rtn)
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (rtn);
}
