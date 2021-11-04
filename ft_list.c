/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:01:24 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/03 18:00:30 by jfieux           ###   ########.fr       */
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
