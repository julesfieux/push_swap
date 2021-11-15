# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 15:04:16 by jfieux            #+#    #+#              #
#    Updated: 2021/11/12 15:23:07 by jfieux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC	=	gcc

FLAG	=	-Wall -Wextra -Werror -g

SRC	=	ft_algo.c \
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

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "OBJS deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:	fclean all

.PHONY:	all, clean, fclean, re