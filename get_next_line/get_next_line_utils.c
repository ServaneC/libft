/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:18:45 by schene            #+#    #+#             */
/*   Updated: 2020/05/14 01:03:05 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cmp;

	i = 0;
	cmp = c;
	if (!s)
		return (NULL);
	while (((s[i] + 1 && cmp == '\0') || s[i]) && s != NULL)
	{
		if (s[i] == cmp)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_newstr(int size)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	join = NULL;
	if (!(join = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}


int		gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(copy = malloc(sizeof(char) * (gnl_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
