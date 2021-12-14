/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:58:03 by jfieux            #+#    #+#             */
/*   Updated: 2021/12/14 11:17:13 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_found_return(char *str);
int		ft_strlen(const char *str);
void	ft_move(char *str, t_begin *begin);
void	ft_check_stack(t_stack *bi, t_stack *bb, t_begin *begin, char *str);
t_begin	*ft_init_begin(void);
void	ft_bzero(void *s, size_t n);
t_stack	*ft_build_stack_str(char *argv, t_begin *begin, int i);
char	**ft_split(char const *s, char c, int i, int j);
int		ft_atoi(char *str, t_begin *begin);
void	ft_check_doublon_str(int *tab, int i, int n, t_begin *begin);
t_stack	*ft_stacknew(int n);
t_stack	*ft_build_stack(int argc, char **argv, t_begin *begin);
t_stack	*ft_swap_stack(t_stack **bi);
t_stack	*ft_push_stack(t_stack **bf, t_stack **bi);
t_stack	*ft_rotate_stack(t_stack **bi);
t_stack	*ft_reverse_rotate_stack(t_stack **bi);
void	ft_rr(t_stack **bi);
void	ft_free(t_begin *begin);
void	ft_lstdel2(t_stack **begin);

#endif
