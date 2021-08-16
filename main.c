/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:06:40 by jfieux            #+#    #+#             */
/*   Updated: 2021/08/16 18:26:41 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		init_struct(t_struct *info, int ac, char **av)
{
	int i;
t_list **lst;

	info = malloc(sizeof(t_struct));
	if (!info)
		return (-1);
	info->start_a = malloc(sizeof(t_list));
	if (!info->start_a)
		return (-1);
	info->start_b = malloc(sizeof(t_list));
	if (!info->start_b)
		return (-1);
	i = 1;
	while (i < ac)
	{
		if (ft_lstadd_back(info->start_a, av[i]) < 0)
			return (-1);
		i++;
	}

lst = info->start_a;
printf("stack a:\n");
i = ft_lstsize(*lst);
printf("size_a = %d\n\n", i);

lst = info->start_b;
printf("stack b:\n");
i = ft_lstsize(*lst);
printf("size_b = %d\n", i);

	return (0);
}

int		main(int ac, char **av)
{
	t_struct *info;

	if (ac < 2)
		return (0);
	info = NULL;
	if (init_struct(info, ac, av) < 0)
	{
		ft_putstr("Error\n", 1);
		return (0);
	}
}