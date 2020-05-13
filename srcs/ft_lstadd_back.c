/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:24:42 by schene            #+#    #+#             */
/*   Updated: 2020/05/14 00:54:23 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst == NULL)
		return ;
	last = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
