/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:04:42 by jfieux            #+#    #+#             */
/*   Updated: 2021/08/16 18:19:36 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				nb;
	struct s_list	*next;
}					t_list;

typedef struct		s_struct
{
	char			*res;
	t_list			**start_a;
	t_list			**start_b;
	
}					t_struct;

void	ft_putstr(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_lstadd_back(t_list **start, char *nb);
int		ft_lstsize(t_list *lst);
int		swap_a(t_struct *info);


#endif
