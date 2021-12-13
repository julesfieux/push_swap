/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:05:53 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/12 17:24:37 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s1;

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
	int	j;
	int	k;

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
	int	j;
	int	k;

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

char	**ft_split(char const *s, char c, int i, int j)
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
		exit(0);
	if (!(ft_malword(c, 0, s, res)))
		exit(0);
	res = ft_init(s, c, res, 0);
	return (res);
}

int	atoi_2(char *str, t_begin *begin, int i, long int res)
{
	if (str[i] > '9' || str[i] < '0')
	{
		write(2, "Error\n", 6);
		ft_free(begin);
		exit(0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if ((str[i] > '9' || str[i] < '0') && str[i] != '\0')
	{
		write(2, "Error\n", 6);
		ft_free(begin);
		exit(0);
	}
	return (res);
}

int	ft_atoi(char *str, t_begin *begin)
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
	res = atoi_2(str, begin, i, res);
	res = res * sign;
	if (res > 2147483647 || res < -2147483648)
	{
		write(2, "Error\n", 6);
		ft_free(begin);
		exit(0);
	}
	return (res);
}
