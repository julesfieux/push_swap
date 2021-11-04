/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_fonction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:07:45 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/03 18:09:03 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_len(t_stack **bi)
{
	t_stack		*elem;
	int			i;

	elem = *bi;
	i = 0;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

int		ft_is_sort(t_stack **begin, int stack)
{
	int		i;
	t_stack	*e;		//chiffre actuel
	t_stack	*next;	//chiffre suivant

	i = 0;
	e = *begin;
	next = e->next;
	while (i < ft_find_len(begin) - 1)
	{
		if ((e->data < next->data && stack == 1)
			|| (e->data > next->data && stack == 2))
		{
			e = e->next;
			next = e->next;
			i++;
		}
		else
			return (1);
	}
	return (0);
}
