/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:57:56 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/04 10:10:52 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sort_2_elem(t_begin *begin)
{
	t_stack *elem;

	elem = begin->ba;
	if (elem->data > elem->next->data)
	{
		begin->ba = ft_swap_stack(&begin->ba);
		ft_instruction(&begin->inst, 1);
	}
}

static void		ft_rot(t_stack **e, t_stack **s, t_begin *begin)
{
	t_stack		*elem;
	t_stack		*suiv;

	elem = *e;
	suiv = *s;
	if (elem->data < suiv->data)	//obligatoire?
	{
		if (elem->data < suiv->next->data)
		{
			begin->ba = ft_reverse_rotate_stack(&begin->ba);
			ft_instruction(&begin->inst, 7);
		}
		else
		{
			begin->ba = ft_rotate_stack(&begin->ba);		//rra n'est pas mieux?
			ft_instruction(&begin->inst, 5);
		}
	}
}

void			ft_sort_3_elem(t_begin *begin)
{
	t_stack		*elem;
	t_stack		*suiv;

	while (begin->ba != NULL && ft_is_sort(&begin->ba, 1) != 0)	//tant que fin de stack ou stack triée
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
