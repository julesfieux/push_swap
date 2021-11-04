/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:12:15 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/04 10:12:41 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_work_a(t_begin *begin, int len)
{
	int			r;
	int			p;
	t_stack		*tmp;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		ft_sort_min_a(begin);
		return ;
	}
	if (begin->ba != NULL && ft_is_sort(&begin->ba, 1) == 0)	//si triée, arrete la
		return ;
	ft_median_sort(begin, len, &r, &p);		//premier trie en fonction du chiffre median
	ft_place(begin, &r);		//remet la stack a dans le meme ordre qu'avant median_sort mais sans les chiffres push dans la stack b
	ft_work_a(begin, (len - p));	//recursive de ce qu'on vient de faire
	ft_work_b(begin, p);
	while (p-- && begin->bb != NULL)
	{
		tmp = begin->bb->next;
		begin->ba = ft_push_stack(&begin->ba, &begin->bb);
		begin->bb = tmp;
		ft_instruction(&begin->inst, 3);
	}
}
