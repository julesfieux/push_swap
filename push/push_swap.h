/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:04:42 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/12 17:48:53 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}	t_stack;

typedef struct s_begin
{
	struct s_stack	*ba;
	struct s_stack	*bb;
	struct s_stack	*inst;
}	t_begin;

t_begin	*ft_init_begin(void);
void	ft_bzero(void *s, size_t n);
t_stack	*ft_build_stack_str(char *argv, t_begin *begin, int i);
char	**ft_split(char const *s, char c, int i, int j);
int		ft_atoi(char *str, t_begin *begin);
void	ft_check_doublon_str(int *tab, int i, int n, t_begin *begin);
t_stack	*ft_stacknew(int n);
t_stack	*ft_build_stack(int argc, char **argv, t_begin *begin);
int		ft_is_sort(t_stack **begin, int stack);
int		ft_find_len(t_stack **bi);
void	ft_sort_2_elem(t_begin *begin);
t_stack	*ft_swap_stack(t_stack **bi);
void	ft_instruction(t_stack **inst, int n);
int		ft_algo(t_begin *begin);
void	ft_sort_3_elem(t_begin *begin);
t_stack	*ft_rotate_stack(t_stack **bi);
t_stack	*ft_reverse_rotate_stack(t_stack **bi);
void	ft_rr(t_stack **bi);
void	ft_sort_min_a(t_begin *begin);
int		ft_median(t_stack **begin, int stack, int n);
int		ft_compare_with_median(t_begin *begin, int n, int median, int stack);
t_stack	*ft_push_stack(t_stack **bf, t_stack **bi);
void	ft_work_a(t_begin *begin, int len);
void	ft_work_b(t_begin *begin, int len);
void	ft_sort_min_b(t_begin *begin);
void	ft_free(t_begin *begin);
void	ft_lstdel2(t_stack **begin);
int		ft_count(char *s, t_begin *begin);

#endif
