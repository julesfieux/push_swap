/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:21:46 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/04 10:11:39 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_instruction(t_stack **inst, int n)
{
	t_stack		*e;
	t_stack		*new;

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

int			ft_algo(t_begin *begin)
{
	int			n;		//taille de la stack a

	n = ft_find_len(&begin->ba);
	if (n == 1)
		return (0);
	else if (n == 2)
		ft_sort_2_elem(begin);
	else if (n == 3)
		ft_sort_3_elem(begin);
	else
		ft_work_a(begin, ft_find_len(&begin->ba));	//pk ne pas mettre n?
	//ft_print_instruction(begin);
	return (0);
}