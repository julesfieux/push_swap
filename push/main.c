/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:06:40 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/22 15:54:47 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_begin *begin)
{
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	ft_lstdel2(&begin->inst);
	free(begin);
}

void	print_stack(t_begin *begin)
{
	t_stack *stack;

	stack = begin->ba;
	printf("\nstack a:\n");
	while (stack != NULL)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

int		main(int argc, char **argv)
{
	t_begin		*begin;

	if (argc == 1)		//pas d'argument
		exit(0);
	begin = ft_init_begin();
	begin->bb = NULL;
	begin->inst = NULL;
	if (argc == 2)		//init si la stack est defini en une string
		begin->ba = ft_build_stack_str(argv[1], begin);
	else				//init si la stack est défini en plusieurs arguments
		begin->ba = ft_build_stack(argc, argv, begin);
	if (ft_is_sort(&begin->ba, 1) != 0)		//si stack a est triée retourne 0
		ft_algo(begin);
	//print_stack(begin);
	ft_free(begin);
	return (0);
}
