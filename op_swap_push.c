/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:59:06 by jfieux            #+#    #+#             */
/*   Updated: 2021/08/16 18:19:53 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int		swap_a(t_struct *info)
{
	int		tmp;
	char	*op;

	if (tab->nba <= 1)
		return (0);
	op = malloc(sizeof(char) * 4);
	if (!op)
		return (-1);
	op[0] = 's';
	op[1] = 'a';
	op[2] = '\n';
	op[3] = '\0';
	temp = tab->a[0];
	tab->a[0] = tab->a[1];
	tab->a[1] = temp;
	tab->res = ft_strjoin(tab->res, op);
	if (!tab->res)
		return (-1);
	return (0);
}*/

/*int		swap_b(t_struct *tab)
{
	int		temp;
	char	*op;

	if (tab->nbb <= 1)
		return (0);
	op = malloc(sizeof(char) * 4);
	if (!op)
		return (-1);
	op[0] = 's';
	op[1] = 'b';
	op[2] = '\n';
	op[3] = '\0';
	temp = tab->b[0];
	tab->b[0] = tab->b[1];
	tab->b[1] = temp;
	tab->res = ft_strjoin(tab->res, op);
	if (!tab->res)
		return (-1);
	return (0);
}

int		swap_ab(t_struct *tab)
{
	int		temp;
	char	*op;

	if (tab->nba <= 1 || tab->nbb <= 1)
	{
		op = malloc(sizeof(char) * 4);
		if (!op)
			return (-1);
		op[0] = 's';
		op[1] = 's';
		op[2] = '\n';
		op[3] = '\0';
		tab->res = ft_strjoin(tab->res, op);
		if (!tab->res)
			return (-1);
	}
	if (tab->nba > 1)
	{
		temp = tab->a[0];
		tab->a[0] = tab->a[1];
		tab->a[1] = temp;
	}
	if (tab->nbb > 1)
	{
		temp = tab->b[0];
		tab->b[0] = tab->b[1];
		tab->b[1] = temp;
	}
	return (0);
}

int		push_a(t_struct *tab)
{
	char *op;

	if (tab->nbb <= 0)
		return (0);
	op = malloc(sizeof(char) * 4);
	if (!op)
		return (-1);
	tab->res = ft_strjoin(tab->res, op);
	if (!tab->res)
		return (-1);
	
}*/
