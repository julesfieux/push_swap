/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:58 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/17 10:38:39 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_swap_stack(t_stack **bi)
{
	t_stack		*elem;		//la stack a
	int			tmp;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	tmp = elem->next->data;
	elem->next->data = elem->data;
	elem->data = tmp;
	*bi = elem;
	return (*bi);
}

t_stack	*ft_push_stack(t_stack **bf, t_stack **bi)	//push le premiere elem de bi sur bf
{
	t_stack		*elem;

	elem = *bi;
	if (elem == NULL)
		return (*bf);
	elem->next = *bf;
	*bf = elem;
	return (*bf);
}

t_stack	*ft_rotate_stack(t_stack **bi)
{
	t_stack		*elem;
	int			tmp;

	elem = *bi;
	tmp = elem->data;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	while (elem->next != NULL)
	{
		elem->data = elem->next->data;
		elem = elem->next;
	}
	elem->data = tmp;
	return (*bi);
}

t_stack	*ft_reverse_rotate_stack(t_stack **bi)
{
	t_stack		*elem;
	int			tmp0;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	while (elem->next != NULL)
		elem = elem->next;
	tmp0 = elem->data;
	ft_rr(bi);
	elem = *bi;
	elem->data = tmp0;
	return (*bi);
}
