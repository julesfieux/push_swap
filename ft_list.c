/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:01:24 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/04 10:10:42 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_begin		*ft_init_begin(void)
{
	t_begin		*begin;

	if (!(begin = (t_begin*)malloc(sizeof(t_begin))))		//(t_begin*)?
		exit(1);
	ft_bzero(begin, sizeof(t_begin));		//initialise begin à 0
	return (begin);
}

t_stack		*ft_stacknew(int n)
{
	t_stack		*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		exit(0);
	new->data = n;
	new->next = NULL;
	return (new);
}

void		ft_rr(t_stack **bi)
{
	t_stack		*elem;
	int			tmp;
	int			tmp2;
	int			i;

	elem = *bi;
	i = 0;
	while (elem != NULL)
	{
		if (i % 2 != 0)
		{
			tmp2 = elem->data;
			elem->data = tmp;
		}
		else if (i % 2 == 0)
		{
			tmp = elem->data;
			elem->data = tmp2;
		}
		i++;
		elem = elem->next;
	}
}
