/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_fonction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:07:45 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/12 17:35:35 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_len(t_stack **bi)
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

int	ft_is_sort(t_stack **begin, int stack)
{
	int		i;
	t_stack	*e;
	t_stack	*next;

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

void	ft_sort_tab(int *tab, int len)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	ft_median(t_stack **begin, int stack, int n)
{
	t_stack	*tmp;
	int		i;
	int		*tab;
	int		median;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (n + 1));
	if (!tab)
		exit(1);
	tmp = *begin;
	while (i < n)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	ft_sort_tab(tab, n);
	if (stack == 2 && n % 2 == 0)
		median = tab[(n / 2) - 1];
	else
		median = tab[(n / 2)];
	free(tab);
	return (median);
}

int	ft_compare_with_median(t_begin *begin, int n, int median, int stack)
{
	int		i;
	t_stack	*elem;

	i = 0;
	if (stack == 1)
		elem = begin->ba;
	else if (stack == 2)
		elem = begin->bb;
	while (i < n)
	{
		if (stack == 1 && elem->data < median)
			return (1);
		if (stack == 2 && elem->data > median)
			return (1);
		i++;
		elem = elem->next;
	}
	return (0);
}
