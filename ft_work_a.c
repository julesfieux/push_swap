/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:12:15 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/04 10:28:54 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_median_sort(t_begin *begin, int len, int *r, int *p)
{
	int		i;		//count
	int		median;
	t_stack	*tmp;

	i = 0;
	median = ft_median(&begin->ba, 1, len);	//trouve le chiffre median
	while (ft_compare_with_median(begin, len - i, median, 1) != 0 && i++ < len)
	{
		if (begin->ba->data < median)
		{
			tmp = begin->ba->next;
			begin->bb = ft_push_stack(&begin->bb, &begin->ba);
			begin->ba = tmp;
			ft_instruction(&begin->inst, 4);
			*p = *p + 1;	//simplification *p++
		}
		else
		{
			begin->ba = ft_rotate_stack(&begin->ba);
			ft_instruction(&begin->inst, 5);
			*r = *r + 1;	//simplification *r++
		}
	}
}

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
	//ft_place(begin, &r);		//remet la stack a dans le meme ordre qu'avant median_sort mais sans les chiffres push dans la stack b
	ft_work_a(begin, (len - p));	//recursive de ce qu'on vient de faire
	//ft_work_b(begin, p);
	while (p-- && begin->bb != NULL)
	{
		tmp = begin->bb->next;
		begin->ba = //ft_push_stack(&begin->ba, &begin->bb);
		begin->bb = tmp;
		ft_instruction(&begin->inst, 3);
	}
}
