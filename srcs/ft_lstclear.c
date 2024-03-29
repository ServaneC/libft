/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:15:46 by schene            #+#    #+#             */
/*   Updated: 2020/05/14 00:54:23 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	int		size;
	int		i;

	if (!(lst && del))
		return ;
	i = 0;
	size = ft_lstsize(*lst);
	while (i != size)
	{
		last = ft_lstnew(NULL);
		last = ft_lstlast(*lst);
		last->next = NULL;
		ft_lstdelone(last, del);
		i++;
	}
	*lst = NULL;
}
