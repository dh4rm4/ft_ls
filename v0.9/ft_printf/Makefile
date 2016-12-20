#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboddez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:52:09 by kboddez           #+#    #+#              #
#    Updated: 2016/12/14 09:51:01 by kboddez          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIB_NAME = libft.a

SRC_NAME = ft_printf.c ft_int.c ft_string.c ft_char.c ft_ptr.c \
	ft_options_sign.c ft_option.c ft_length.c ft_precision.c \
	ft_itoa_maj.c ft_format_i.c ft_putstr_cpt.c ft_putwchar.c \
	ft_format_ii.c ft_format_iii.c ft_format_iv.c ft_wlen.c \
	ft_format_v.c ft_unput.c ft_print.c ft_check.c ft_test.c \
	printf_itoa.c ft_itoa_base.c printf_nbr_length.c ft_putchar.c ft_putstr.c \
	ft_strlen.c ft_strnew.c ft_isascii.c ft_memalloc.c ft_bzero.c \
	ft_putnbr.c ft_nbrendl.c ft_options_sign_iii.c printf_isdigit.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME):
	@gcc -c $(CFLAGS) $(SRC_NAME)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *~
	@/bin/rm -f ./*~
	@/bin/rm -f *#

re: fclean all

