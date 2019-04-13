# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrameau <jrameau@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:58:27 by jrameau           #+#    #+#              #
#    Updated: 2019/04/13 01:24:32 by bchapman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CFLAGS= -I $(INCLUDES) -Wall -Wextra -Werror
INCLUDES = libft.h

FILES		= ft_bzero.c \
			  	ft_ftoa.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_itoa_base_lower.c \
				ft_itoa_unsigned.c \
				ft_memalloc.c \
				ft_print_pointer_memory.c \
				ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_strchri.c \
				ft_strlen.c \
				ft_strnew.c \
				ft_strsub.c \
				parse_csp.c \
				parse_dioux.c \
				parse_float.c

OBJ=$(FILES:.c=.o)

$(NAME):
	gcc $(CFLAGS) -c $(FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
