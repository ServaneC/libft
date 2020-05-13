# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schene <schene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:00:19 by schene            #+#    #+#              #
#    Updated: 2020/05/13 19:08:54 by schene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_memset.c srcs/ft_bzero.c srcs/ft_memcpy.c srcs/ft_memccpy.c \
			srcs/ft_memmove.c srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_strlen.c \
			srcs/ft_isalpha.c srcs/ft_isdigit.c srcs/ft_isalnum.c srcs/ft_isascii.c \
			srcs/ft_isprint.c srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_strchr.c \
			srcs/ft_strrchr.c srcs/ft_strncmp.c  srcs/ft_strlcpy.c srcs/ft_strlcat.c \
			srcs/ft_strnstr.c srcs/ft_atoi.c srcs/ft_calloc.c srcs/ft_strdup.c \
			srcs/ft_substr.c srcs/ft_strjoin.c srcs/ft_strtrim.c srcs/ft_split.c \
			srcs/ft_itoa.c srcs/ft_strmapi.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c \
			srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c srcs/ft_putchar.c srcs/ft_putstr.c \
			srcs/ft_putnbr.c srcs/ft_put_unsigned_nbr.c srcs/ft_putnbr_base.c srcs/ft_putptr.c \
			srcs/ft_puthexa_min.c srcs/ft_puthexa_maj.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			ft_printf/srcs/ft_putchar_pf.c ft_printf/srcs/ft_putstr_pf.c ft_printf/srcs/ft_putptr_pf.c \
			ft_printf/srcs/ft_putnbr_pf.c ft_printf/srcs/ft_put_unsigned_nbr_pf.c \
			ft_printf/srcs/ft_puthexa_min_pf.c ft_printf/srcs/ft_puthexa_maj_pf.c \
			ft_printf/srcs/ft_putmodulo.c ft_printf/srcs/ft_printf.c ft_printf/srcs/ft_printf_utils.c

SBONUS	= srcs/ft_lstnew.c srcs/ft_lstadd_front.c srcs/ft_lstsize.c srcs/ft_lstlast.c \
			srcs/ft_lstadd_back.c srcs/ft_lstdelone.c srcs/ft_lstclear.c srcs/ft_lstiter.c \
			srcs/ft_lstmap.c


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

