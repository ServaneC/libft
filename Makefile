# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schene <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:00:19 by schene            #+#    #+#              #
#    Updated: 2019/11/13 14:56:46 by schene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		  	ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c  \
			ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c \
			ft_putstr.c ft_putnbr.c ft_put_unsigned_nbr.c ft_putnbr_base.c ft_putptr.c

SBONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS	= ${SRCS:.c=.o}

OBONUS	= ${SBONUS:.c=.o}

NAME	= libft.a

RM	= rm -f

CC	= gcc

CFLAGS	= -I includes -Wall -Wextra -Werror

all:		${NAME}

$(NAME): 	${OBJS}
			ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${OBONUS} 
			ar rc ${NAME} ${OBJS} ${OBONUS}

clean:
			${RM} ${OBJS} ${OBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re

