/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:42 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:50:36 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				num;
	int				mark;
	int				pivot;
	struct s_list	*next;
}	t_list;

void	check_arg(int ac, char **argv, t_list **head_a);

t_list	*ft_lstnew(int num);
void	ft_lst_add_back(t_list **head, t_list *new);
int		ft_lstsize(t_list *head);
int		is_sorted(t_list *head);
int		is_all_sorted(t_list *a, t_list *b);
int		is_duplicated(t_list *head);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	pb(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
void	sort(t_list **head, t_list **head_b);
void	small_sort(t_list **head, int ch);
void	sort_three_a(t_list **a);
void	sort_three_b(t_list **b);
void	sort_big(t_list **a, t_list **b);
void	push_b_half(t_list **a, t_list **b);
void	push_a_until_3(t_list **a, t_list **b);
void	push_a_sorted_num(t_list **a, t_list **b);
int		count_same_pivot(t_list *head, int p);
void	p_num_is_two(t_list **a, t_list **b, int p_num);
void	p_num_is_three(t_list **a, t_list **b, int p_num);
void	more_p_num(t_list **a, t_list **b, int p_num);
int		ft_min(t_list *head);
int		ft_max(t_list *head);

int		find_idx(t_list *head, int nb);
int		get_pivot(t_list *a, int size);

void	error_and_exit(char *msg);
void	free_2d(char **ptr);
void	free_list(t_list *head);
#endif
