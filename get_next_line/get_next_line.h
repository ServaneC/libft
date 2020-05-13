/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:19:05 by schene            #+#    #+#             */
/*   Updated: 2020/05/13 17:30:52 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFFER_SIZE 10

int		gnl_strlen(const char *s);
int		ft_delstr(char **mem, int ret, int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_newstr(int size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ret_end(char **mem, int ret, int fd);
int		ft_line(char **s, char **line, int fd, int ret);
int		get_next_line(int fd, char **line);

#endif
