/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:05:53 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/03 12:24:50 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char *s1;

	s1 = (char *)s;
	while (n > 0)
	{
		*s1 = 0;
		s1++;
		n--;
	}
}

static char	**ft_init(const char *s, char c, char **res, int i)
{
	int j;
	int k;

	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
			{
				res[k][j] = s[i];
				j++;
				i++;
			}
			res[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	res[k] = NULL;
	return (res);
}

static int	ft_malword(int c, int i, const char *s, char **res)
{
	int j;
	int k;

	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
			{
				j++;
				i++;
			}
			res[k] = malloc(sizeof(char) * (j + 1));
			if (!res[k])
				return (0);
			k++;
		}
		else
			i++;
	}
	return (1);
}

char		**ft_split(char const *s, char c, int i, int j)
{
	char	**res;

	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			j++;
		}
		else
			i++;
	}
	res = malloc(sizeof(char *) * (j + 1));
	if (!res)
		return (0);
	if (!(ft_malword(c, 0, s, res)))
		return (0);
	res = ft_init(s, c, res, 0);
	return (res);
}

int		ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (sign == 1 && res > 922337203685477580)
			return (-1);
		else if (res > 922337203685477580)
			return (0);
	}
	return (res * sign);
}