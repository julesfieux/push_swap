/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:21:46 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/13 10:55:38 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruction(t_stack **inst, int n)
{
	t_stack	*e;
	t_stack	*new;

	e = *inst;
	if (e != NULL)
	{
		while (e->next != NULL)
			e = e->next;
		new = ft_stacknew(n);
		e->next = new;
	}
	else
		*inst = ft_stacknew(n);
}

static void	ft_print_instruction_2(t_stack *e)
{
	if (e->data == 3)
		printf("pa\n");
	else if (e->data == 4)
		printf("pb\n");
	else if (e->data == 5)
		printf("ra\n");
	else if (e->data == 6)
		printf("rb\n");
	else if (e->data == 7)
		printf("rra\n");
	else if (e->data == 8)
		printf("rrb\n");
}

static void	ft_print_instruction(t_begin *begin)
{
	t_stack	*e;
	t_stack	*next;

	e = begin->inst;
	while (e != NULL)
	{
		next = NULL;
		if (e->next != NULL)
			next = e->next;
		if (e->data == 1 && (!next || next->data != 2))
			printf("sa\n");
		else if (e->data == 2 && (!next || next->data != 1))
			printf("sb\n");
		else if ((e->data == 1 && (!next || next->data == 2))
			|| (e->data == 2 && (!next || next->data == 1)))
		{
			printf("ss\n");
			e = e->next;
		}
		else
			ft_print_instruction_2(e);
		e = e->next;
	}
}

int	ft_algo(t_begin *begin)
{
	int	n;

	n = ft_find_len(&begin->ba);
	if (n == 1)
		return (0);
	else if (n == 2)
		ft_sort_2_elem(begin);
	else if (n == 3)
		ft_sort_3_elem(begin);
	else
		ft_work_a(begin, n);
	ft_print_instruction(begin);
	return (0);
}
