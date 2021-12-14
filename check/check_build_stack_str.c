/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_build_stack_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:08:51 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/13 14:59:23 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long int	ft_atoi_str_2(char **s, int j)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((s[j][i] >= 9 && s[j][i] <= 13) || s[j][i] == ' ')
		i++;
	if (s[j][i] == '-' || s[j][i] == '+')
	{
		if (s[j][i] == '-')
			sign = -sign;
		i++;
	}
	while (s[j][i] >= '0' && s[j][i] <= '9')
	{
		res = (res * 10) + (s[j][i] - '0');
		i++;
	}
	res = res * sign;
	return (res);
}

void	ft_atoi_str_3(char **s, int n)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	*ft_atoi_str(char **s, int n, t_begin *begin)
{
	int			j;
	int			*temp;
	long int	res;

	j = 0;
	temp = malloc(sizeof(int) * n + 1);
	if (!temp)
		exit(0);
	while (j < n)
	{
		res = ft_atoi_str_2(s, j);
		if (res > 2147483647 || res < -2147483648)
		{
			ft_atoi_str_3(s, n);
			free(temp);
			ft_free(begin);
			exit(0);
		}
		temp[j] = res;
		j++;
	}
	return (temp);
}

static int	*ft_fill_tab(char *str, int n, t_begin *begin)
{
	int		*tab;
	char	**s;

	s = ft_split(str, ' ', 0, 0);
	tab = ft_atoi_str(s, n, begin);
	while (n >= 0)
	{
		free(s[n]);
		n--;
	}
	free(s);
	return (tab);
}

t_stack	*ft_build_stack_str(char *argv, t_begin *begin, int i)
{
	t_stack		*ea;
	t_stack		*ba;
	int			n;
	int			*tab;

	ea = NULL;
	ba = NULL;
	if (i == 0)
	{
		ft_free(begin);
		exit(0);
	}
	tab = ft_fill_tab(argv, i, begin);
	i--;
	while (i >= 0)
	{
		n = tab[i];
		ft_check_doublon_str(tab, i, ft_count(argv, begin), begin);
		ea = ft_stacknew(n);
		ea->next = ba;
		ba = ea;
		i--;
	}
	free(tab);
	return (ba);
}
