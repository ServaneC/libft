/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:43:22 by schene            #+#    #+#             */
/*   Updated: 2020/05/14 00:54:23 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size < 1 || count < 1)
	{
		if (!(mem = malloc(1)))
			return (NULL);
	}
	else if (!(mem = malloc(size * count)))
		return (NULL);
	ft_bzero(mem, (size * count));
	return (mem);
}
