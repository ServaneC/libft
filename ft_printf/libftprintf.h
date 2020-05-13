/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:51:13 by schene            #+#    #+#             */
/*   Updated: 2020/05/14 00:55:32 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../srcs/my_libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_flags
{
	int				size;
	int				precision;
	char			c;
	int				side;
}					t_flags;

int					ft_putchar_pf(va_list *ap, t_flags *param);
int					ft_putstr_pf(va_list *ap, t_flags *param);
int					ft_putnbr_pf(va_list *ap, t_flags *param);
int					ft_putptr_pf(va_list *ap, t_flags *param);
int					ft_put_unsigned_nbr_pf(va_list *ap, t_flags *param);
int					ft_puthexa_min_pf(va_list *ap, t_flags *param);
int					ft_puthexa_maj_pf(va_list *ap, t_flags *param);
int					ft_putmodulo(va_list *ap, t_flags *param);
int					find_p(int len, int precision, int i);
int					check_minus(char *s_nb);
int					ft_fill_right(char c, int i, int p, int sz);
void				ft_fill_left(int side, int sz, int p, char *s_nb);
int					ft_fill_middle(char *s_nb, char c, int sz, int p);
t_flags				*new_param(void);
int					fill_size(t_flags *param, char *flags, int i, va_list *ap);
int					fill_param(t_flags *param, char *flags, va_list *ap);
int					print_result(char *flags,
						int (*tab_f[8]) (va_list *, t_flags *),
							char *tab_idx, va_list *ap);
int					search_index(char c, char tab_idx[10]);
int					is_flag(char c);
int					check_valid(char *str, char *tab_idx);
int					ft_printf(const char *format, ...);

#endif
