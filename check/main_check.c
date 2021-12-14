/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:57:19 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/14 11:24:44 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_count(char *s, t_begin *begin)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			i++;
		else if (((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-')
			&& (i == 0 || s[i - 1] == ' '))
		{
			i++;
			k++;
		}
		else if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
		{
			write(2, "Error\n", 6);
			ft_free(begin);
			exit(1);
		}
		else if (s[i] >= '0' && s[i] <= '9')
			i++;
	}
	return (k);
}

void	ft_free(t_begin *begin)
{
	ft_lstdel2(&begin->ba);
	ft_lstdel2(&begin->bb);
	ft_lstdel2(&begin->inst);
	free(begin);
}

int	main(int argc, char **argv)
{
	char		*str;
	t_begin		*begin;

	if (argc == 1)
		exit(0);
	begin = ft_init_begin();
	begin->bb = NULL;
	if (argc == 2)
		begin->ba = ft_build_stack_str(argv[1],
				begin, ft_count(argv[1], begin));
	else
		begin->ba = ft_build_stack(argc, argv, begin);
	str = NULL;
	while (get_next_line(0, &str) == 1)
	{
		ft_move(str, begin);
		free(str);
	}
	ft_check_stack(begin->ba, begin->bb, begin, str);
	free(str);
	ft_free(begin);
	return (0);
}
