/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:06:40 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/10 11:37:42 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_begin		*begin;

	begin = ft_init_begin();
	begin->bb = NULL;
	begin->inst = NULL;
	if (argc == 1)		//pas besoin de trier
		exit(0);
	if (argc == 2)		//init si la stack est defini en une string
		begin->ba = ft_build_stack_str(argv[1]);
	else				//init si la stack est défini en plusieurs arguments
		begin->ba = ft_build_stack(argc, argv);
	if (ft_is_sort(&begin->ba, 1) != 0)		//si stack a est triée retourne 0
		ft_algo(begin);
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	ft_lstdel2(&begin->inst);
	free(begin);
	return (0);
}
