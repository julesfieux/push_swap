/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_build_stack_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:08:51 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/22 16:03:21 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_count(char *s, t_begin *begin)		//compte le nombre de chiffre de la stack
{
	int		i;	//count
	int		k;	//nb de chiffre dans la stack

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i] != '\0')		//le '\0' n'a pas de sens
			i++;
		else if (((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-')
			&& (i == 0 || s[i - 1] == ' ') && s[i] != '\0')		//pareil le '\0' est inutile
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
		else if (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')		//'\0'
			i++;
	}
	return (k);
}

static int		*ft_fill_tab(char *str, int n, t_begin *begin)
{
	int		*tab;
	int		i;
	char	**s;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))		//je ne crois pas que le '+1' est du sens
		exit(1);
	s = ft_split(str, ' ', 0, 0);
	while (i < n)
	{
		tab[i] = ft_atoi(s[i], begin);
		i++;
	}
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (tab);
}

t_stack			*ft_build_stack_str(char *argv, t_begin *begin)
{
	t_stack		*ea;
	t_stack		*ba;
	int			n;
	int			i;	//nb de chiffre dans la stack de start
	int			*tab;

	ea = NULL;
	ba = NULL;
	i = ft_count(argv, begin);
	if (i == 0)
	{
		ft_free(begin);
		exit(0);
	}
	tab = ft_fill_tab(argv, i, begin);
	i--;		//i est donc au dernier chiffre de la stack
	while (i >= 0)
	{
		n = tab[i];
		ft_check_doublon_str(tab, i, ft_count(argv, begin), begin);
		ea = ft_stacknew(n);
		ea->next = ba;	//je ne comprends pas pk on fait dans cet ordre
		ba = ea;
		i--;
	}
	free(tab);
	return (ba);
}
