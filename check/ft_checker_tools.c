/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:38:04 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/14 11:47:19 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_move2(char *str, t_begin *begin)
{
	if (str && (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0))
		begin->ba = ft_rotate_stack(&begin->ba);
	else if (str && (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0))
		begin->ba = ft_reverse_rotate_stack(&begin->ba);
	else if (str && (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0))
		begin->bb = ft_rotate_stack(&begin->bb);
	else if (str && (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0))
		begin->bb = ft_reverse_rotate_stack(&begin->bb);
	else if (str && (ft_strcmp(str, "ss") == 0))
	{
		begin->ba = ft_swap_stack(&begin->ba);
		begin->bb = ft_swap_stack(&begin->bb);
	}
	else if ((str && (ft_strcmp(str, "pa") == 0) && begin->bb == NULL)
		|| (str && (ft_strcmp(str, "pb") == 0) && begin->ba == NULL))
		return ;
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_move(char *str, t_begin *begin)
{
	t_stack		*tmp;

	if (str && (ft_strcmp(str, "sa") == 0))
		begin->ba = ft_swap_stack(&begin->ba);
	else if (str && (ft_strcmp(str, "sb") == 0))
		begin->bb = ft_swap_stack(&begin->bb);
	else if (str && (ft_strcmp(str, "pa") == 0) && begin->bb != NULL)
	{
		tmp = begin->bb->next;
		begin->ba = ft_push_stack(&begin->ba, &begin->bb);
		begin->bb = tmp;
	}
	else if (str && (ft_strcmp(str, "pb") == 0) && begin->ba != NULL)
	{
		tmp = begin->ba->next;
		begin->bb = ft_push_stack(&begin->bb, &begin->ba);
		begin->ba = tmp;
	}
	else
		ft_move2(str, begin);
}

void	ft_check_stack_2(t_stack *ba, t_begin *begin, char *str)
{
	int		n;

	if (ba != NULL)
	{
		n = ba->data;
		ba = ba->next;
	}
	while (ba != NULL)
	{
		if (ba->data > n)
		{
			n = ba->data;
			ba = ba->next;
		}
		else
		{
			printf("KO\n");
			free(str);
			ft_free(begin);
			exit(0);
		}
	}
}

void	ft_check_stack(t_stack *ba, t_stack *bb, t_begin *begin, char *str)
{
	ft_check_stack_2(ba, begin, str);
	if (bb == NULL)
		printf("OK\n");
	else
		printf("KO\n");
}
