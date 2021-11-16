/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:58:03 by jfieux            #+#    #+#             */
/*   Updated: 2021/11/16 14:53:44 by jfieux           ###   ########.fr       */
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
void	ft_check_stack(t_stack **bi, t_stack **bb);

#endif
