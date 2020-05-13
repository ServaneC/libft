/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:28:56 by schene            #+#    #+#             */
/*   Updated: 2019/12/04 15:44:34 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	*new_param(void)
{
	t_flags *param;

	if (!(param = malloc(sizeof(t_flags))))
		return (NULL);
	param->size = -1;
	param->precision = -1;
	param->c = ' ';
	param->side = 0;
	return (param);
}

int		fill_size(t_flags *param, char *flags, int i, va_list *ap)
{
	if (flags[i] == '*' && ++i)
	{
		param->size = va_arg(*ap, int);
		if (param->size < 0)
		{
			param->side = 1;
			param->size *= -1;
		}
	}
	else if (ft_isdigit(flags[i]))
	{
		param->size = ft_atoi(&flags[i]);
		while (ft_isdigit(flags[i]))
			i++;
	}
	return (i);
}

int		fill_precision(t_flags *param, char *flags, int i, va_list *ap)
{
	if (flags[i] == '*' && ++i)
	{
		param->precision = va_arg(*ap, int);
		if (param->precision < 0)
			param->precision = -1;
	}
	else
	{
		param->precision = ft_atoi(&flags[i]);
		while (ft_isdigit(flags[i]))
			i++;
	}
	return (i);
}

int		fill_param(t_flags *param, char *flags, va_list *ap)
{
	int		i;

	i = 0;
	while (is_flag(flags[i]))
	{
		if (flags[i] == '-' && ++i)
			param->side = 1;
		if (flags[i] == '0' && ++i && (param->side != 1 || flags[i] != '-'))
			param->c = '0';
		i = fill_size(param, flags, i, ap);
		if (flags[i] == '.' && ++i)
			i = fill_precision(param, flags, i, ap);
	}
	return (i);
}

int		print_result(char *flags, int (*tab_f[8]) (va_list *, t_flags *),
				char *tab_idx, va_list *ap)
{
	int				index;
	int				i;
	t_flags			*param;

	i = 0;
	param = new_param();
	if (search_index(flags[i], tab_idx) == -1)
		i = fill_param(param, flags, ap);
	index = search_index(flags[i], tab_idx);
	if ((i = ((*tab_f[index])(ap, param))) == -1)
		return (-1);
	free(param);
	return (i);
}
