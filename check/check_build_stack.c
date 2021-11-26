/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_build_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:56:18 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/22 16:03:58 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_check_doublon_str(int *tab, int i, int n, t_begin *begin)
{
	int		j;

	j = (i != 0 ? i - 1 : 0);	//if i != 0 tu fais j = i - 1 sinon j = 0?
	while (j >= 0)
	{
		if (tab[i] == tab[j] && n != 1 && j != i)		// n ne peut pas etre = à 1
		{
			write(2, "Error\n", 6);
			free(tab);
			ft_free(begin);
			exit(1);
		}
		j--;
	}
}

static void	ft_check_doublon(char **argv, int i, int n, t_begin *begin)
{
	i--;
	while (i > 0)
	{
		if (n == ft_atoi(argv[i], begin))
		{
			write(2, "Error\n", 6);
			ft_free(begin);
			exit(1);
		}
		i--;
	}
}

t_stack		*ft_build_stack(int argc, char **argv, t_begin *begin)
{
	t_stack		*ea;
	t_stack		*ba;
	int			n;
	int			i;

	ea = NULL;
	ba = NULL;
	i = argc - 1;
	while (i > 0)
	{
		n = ft_atoi(argv[i], begin);
		ft_check_doublon(argv, i, n, begin);
		ea = ft_stacknew(n);
		ea->next = ba;	//meme question pk cet ordre
		ba = ea;
		i--;
	}
	return (ba);
}
