/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_fonction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:07:45 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/12 16:35:54 by jfieux           ###   ########.fr       */
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

void	ft_sort_tab(int *tab, int len)
{
	int		i;
	int		tmp;
	int		n;

	i = 0;
	n = i;		//c'est degueut met 0
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = n;		//pk pas mettre 0 direct
		}
		else
			i++;
	}
	i = n;		//à quoi ca sert
}

int		ft_median(t_stack **begin, int stack, int n)
{
	t_stack	*tmp;	//stack a
	int		i;		//count
	int		*tab;	//tableau des chiffre de la stack a
	int		median;	//chiffre au milieu de la stack dans l'odre croissant

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))
		exit(1);
	tmp = *begin;
	while (i < n)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	ft_sort_tab(tab, n);	//trie tout le tab
	if (stack == 2 && n % 2 == 0)
		median = tab[(n / 2) - 1];
	else
		median = tab[(n / 2)];
	free(tab);
	return (median);
}

int		ft_compare_with_median(t_begin *begin, int n, int median, int stack)
{
	int		i;		//count
	t_stack	*elem;	//stack a ou b en fonction de stack

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
