/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:57:19 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/19 13:04:51 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free(t_begin *begin)
{
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	ft_lstdel2(&begin->inst);
	free(begin);
}

int				main(int argc, char **argv)
{
	char		*str;
	t_begin		*begin;

	begin = ft_init_begin();
	begin->bb = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		begin->ba = ft_build_stack_str(argv[1], begin);
	else
		begin->ba = ft_build_stack(argc, argv, begin);
	str = NULL;
	while (get_next_line(0, &str) == 1)
	{
		ft_move(str, begin);
		free(str);
	}
	free(str);
	ft_free(begin);
	return (0);
}
