/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:01:24 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/13 11:01:00 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s1;

	s1 = (char *)s;
	while (n > 0)
	{
		*s1 = 0;
		s1++;
		n--;
	}
}

t_begin	*ft_init_begin(void)
{
	t_begin		*begin;

	begin = malloc(sizeof(t_begin));
	if (!begin)
		exit(1);
	ft_bzero(begin, sizeof(t_begin));
	return (begin);
}

t_stack	*ft_stacknew(int n)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	new->data = n;
	new->next = NULL;
	return (new);
}

void	ft_rr(t_stack **bi)
{
	t_stack	*elem;
	int		tmp;
	int		tmp2;
	int		i;

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

void	ft_lstdel2(t_stack **begin)
{
	t_stack	*tmp;

	while (*begin != NULL)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	free(*begin);
}
