/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:04:42 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/04 09:23:57 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	int				data;
}					t_stack;

typedef struct		s_begin
{
	struct s_stack	*ba;
	struct s_stack	*bb;
	struct s_stack	*inst;
}					t_begin;

t_begin				*ft_init_begin(void);
void				ft_bzero(void *s, size_t n);
t_stack				*ft_build_stack_str(char *argv);
char				**ft_split(char const *s, char c, int i, int j);
int					ft_atoi(char *str);
void				ft_check_doublon_str(int *tab, int i, int n);
t_stack				*ft_stacknew(int n);
t_stack				*ft_build_stack(int argc, char **argv);
int					ft_is_sort(t_stack **begin, int stack);
int					ft_find_len(t_stack **bi);




#endif
