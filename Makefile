# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 15:04:16 by jfieux            #+#    #+#              #
#    Updated: 2021/11/16 15:07:56 by jfieux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P			= push_swap
NAME_C			= checker

CC	=	gcc

FLAG	=	-Wall -Wextra -Werror -g

_SRC_P	=	ft_algo.c \
			ft_build_stack_str.c \
			ft_build_stack.c \
			ft_list.c \
			ft_op_stack.c \
			ft_short_sort.c \
			ft_tools_fonction.c \
			ft_work_a.c \
			ft_work_b.c \
			libft_tools.c \
			main.c

_SRC_C	=	ft_checker_tools.c \
			get_next_line_utils.c \
			get_next_line.c \
			main_check.c

SRC_P_DIR = push
SRC_C_DIR = check
SRC_P = $(addprefix $(SRC_P_DIR)/, $(_SRC_P))
SRC_C = $(addprefix $(SRC_C_DIR)/, $(_SRC_C))
OBJ_P	=	$(SRC_P:.c=.o)
OBJ_C	=	$(SRC_C:.c=.o)

all:	$(NAME_P) $(NAME_C)

$(NAME_P):	$(OBJ_P)
	@$(CC) $(FLAG) $(OBJ_P) -o $(NAME_P)

$(NAME_C):	$(OBJ_C)
	@$(CC) $(FLAG) $(OBJ_C) -o $(NAME_C)

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ_P)
	@rm -f $(OBJ_C)
	@echo "OBJS deleted"

fclean:	clean
	@rm -f $(NAME_P)
	@rm -f $(NAME_C)
	@echo "$(NAME_P) and $(NAME_C) deleted"

re:	fclean all

.PHONY:	all, clean, fclean, re