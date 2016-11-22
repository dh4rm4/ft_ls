#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboddez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/09 12:57:20 by kboddez           #+#    #+#              #
#    Updated: 2016/11/22 14:51:41 by kboddez          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

MAIN = main.c

SRC_NAME =  $(MAIN) ls_start.c ls_storage.c ls_print.c \
	ls_exit.c

GREEN = \033[33;32m
YELLOW = \033[33;33m
RED = \033[33;31m
WHITE = \033[33;37m

SRC_PATH = ./srcs/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

CFLAGS = -Wall -Wextra -Werror -Ofast

all: $(NAME)

$(NAME):
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation libft\t:\t"
#	@make -C ./libft re
	@echo "$(RED)NONE =$(YELLOW)=$(RED)="
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation - flags\t:\t"
	@echo "$(RED)NONE =$(YELLOW)=$(RED)="
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation ft_ls\t:\t"
	@gcc $(CFLAGS_MLX) $(SRC) -L ./libft -lft -o $(NAME)
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

clean:
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Clean\t\t:\t"
#	@make -C ./libft clean
	@/bin/rm -f $(OBJ)
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

fclean: clean
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)FClean\t\t:\t"
#	@make -C ./libft fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f ./src/./*~
	@/bin/rm -f *~
	@/bin/rm -f ./*~
	@/bin/rm -f *#
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

re: fclean all
