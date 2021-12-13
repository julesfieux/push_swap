/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:57:56 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/12 17:38:12 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2_elem(t_begin *begin)
{
	t_stack	*elem;

	elem = begin->ba;
	if (elem->data > elem->next->data)
	{
		begin->ba = ft_swap_stack(&begin->ba);
		ft_instruction(&begin->inst, 1);
	}
}

static void	ft_rot(t_stack **e, t_stack **s, t_begin *begin)
{
	t_stack		*elem;
	t_stack		*suiv;

	elem = *e;
	suiv = *s;
	if (elem->data < suiv->data)
	{
		if (elem->data < suiv->next->data)
		{
			begin->ba = ft_reverse_rotate_stack(&begin->ba);
			ft_instruction(&begin->inst, 7);
		}
		else
		{
			begin->ba = ft_rotate_stack(&begin->ba);
			ft_instruction(&begin->inst, 5);
		}
	}
}

void	ft_sort_3_elem(t_begin *begin)
{
	t_stack		*elem;
	t_stack		*suiv;

	while (begin->ba != NULL && ft_is_sort(&begin->ba, 1) != 0)
	{
		elem = begin->ba;
		suiv = elem->next;
		if (elem->data > suiv->data)
		{
			if (elem->data < suiv->next->data)
			{
				begin->ba = ft_swap_stack(&begin->ba);
				ft_instruction(&begin->inst, 1);
			}
			else
			{
				begin->ba = ft_rotate_stack(&begin->ba);
				ft_instruction(&begin->inst, 5);
			}
		}
		else if (begin->ba != NULL && ft_is_sort(&begin->ba, 1) != 0)
			ft_rot(&elem, &suiv, begin);
	}
}

void	ft_sort_min_a(t_begin *begin)
{
	int	len;

	len = ft_find_len(&begin->ba);
	if (len > 1 && begin->ba->data > begin->ba->next->data)
	{
		begin->ba = ft_swap_stack(&begin->ba);
		ft_instruction(&begin->inst, 1);
	}
	if (len > 2 && begin->ba->next->data > begin->ba->next->next->data)
	{
		begin->ba = ft_rotate_stack(&begin->ba);
		begin->ba = ft_swap_stack(&begin->ba);
		begin->ba = ft_reverse_rotate_stack(&begin->ba);
		ft_instruction(&begin->inst, 5);
		ft_instruction(&begin->inst, 1);
		ft_instruction(&begin->inst, 7);
	}
	if (len > 1 && begin->ba->data > begin->ba->next->data)
	{
		begin->ba = ft_swap_stack(&begin->ba);
		ft_instruction(&begin->inst, 1);
	}
}

void	ft_sort_min_b(t_begin *begin)
{
	int	len;

	len = ft_find_len(&begin->bb);
	if (len > 1 && begin->bb->data < begin->bb->next->data)
	{
		begin->bb = ft_swap_stack(&begin->bb);
		ft_instruction(&begin->inst, 2);
	}
	if (len > 2 && begin->bb->next->data < begin->bb->next->next->data)
	{
		begin->bb = ft_rotate_stack(&begin->bb);
		begin->bb = ft_swap_stack(&begin->bb);
		begin->bb = ft_reverse_rotate_stack(&begin->bb);
		ft_instruction(&begin->inst, 6);
		ft_instruction(&begin->inst, 2);
		ft_instruction(&begin->inst, 8);
	}
	if (len > 1 && begin->bb->data < begin->bb->next->data)
	{
		begin->bb = ft_swap_stack(&begin->bb);
		ft_instruction(&begin->inst, 2);
	}
}
