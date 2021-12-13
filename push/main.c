/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:06:40 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/12 17:58:49 by jfieux           ###   ########.fr       */
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
	t_stack	*stack;

	stack = begin->ba;
	printf("\nstack a:\n");
	while (stack != NULL)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_begin		*begin;

	if (argc == 1)
		exit(0);
	begin = ft_init_begin();
	begin->bb = NULL;
	begin->inst = NULL;
	if (argc == 2)
		begin->ba = ft_build_stack_str(argv[1],
				begin, ft_count(argv[1], begin));
	else
		begin->ba = ft_build_stack(argc, argv, begin);
	if (ft_is_sort(&begin->ba, 1) != 0)
		ft_algo(begin);
	ft_free(begin);
	return (0);
}
