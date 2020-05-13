/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:59:10 by schene            #+#    #+#             */
/*   Updated: 2020/05/14 00:54:23 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cmp;

	i = 0;
	cmp = c;
	while (((s[i] + 1 && cmp == '\0') || s[i]) && s != NULL)
	{
		if (s[i] == cmp)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
