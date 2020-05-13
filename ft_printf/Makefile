# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schene <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 15:44:40 by schene            #+#    #+#              #
#    Updated: 2019/12/04 15:44:45 by schene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_putchar_pf.c srcs/ft_putstr_pf.c srcs/ft_putptr_pf.c \
				srcs/ft_putnbr_pf.c srcs/ft_put_unsigned_nbr_pf.c \
				srcs/ft_puthexa_min_pf.c srcs/ft_puthexa_maj_pf.c \
				srcs/ft_putmodulo.c srcs/ft_printf.c srcs/ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= libft

NAME_LIBFT	= libft.a

NAME		= libftprintf.a

RM			= rm -f

CC			= gcc

CFLAGS		= -I includes -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			@make -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:		
			@make -C $(LIBFT) clean
			${RM} ${OBJS}

fclean:		clean
			cd ${LIBFT} && ${RM} ${NAME_LIBFT}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
