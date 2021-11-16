/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:57:19 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/16 14:55:16 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int argc, char **argv)
{
	char		*str;
	t_begin		*begin;

	begin = ft_init_begin();
	begin->bb = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		begin->ba = ft_build_stack_str(argv[1]);
	else
		begin->ba = ft_build_stack(argc, argv);
	str = NULL;
	while (get_next_line(0, &str) == 1)
	{
		ft_move(str, begin);
		free(str);
	}
	free(str);
	ft_check_stack(&begin->ba, &begin->bb);
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	free(begin);
	return (0);
}
