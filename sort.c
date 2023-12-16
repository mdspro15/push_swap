/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:49:22 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:16:02 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_idx(t_list	*head, int nb);
void	sort_until_six(t_list **a, t_list **b);

void	sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 3)
		small_sort(a, 'a');
	if (ft_lstsize(*a) >= 4 && ft_lstsize(*a) <= 6)
		sort_until_six(a, b);
	if (ft_lstsize(*a) > 6)
		sort_big(a, b);
}

//Find smallest number from stack A
//push to stack B until 3 numbers left in stack A.
//To bring smallest number to top to push, 
//do ra or rra depend on its position.
//If smallest number is close to top do "ra", otherwise do "rra".
//After 3 numbers in A are sorted, push all numbers in B back to A.
void	sort_until_six(t_list **a, t_list **b)
{
	int	i;

	while (ft_lstsize(*a) > 3)
	{
		i = find_idx(*a, ft_min(*a));
		while ((*a)-> num != ft_min(*a))
		{
			if (i <= ft_lstsize(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three_a(a);
	while (ft_lstsize(*b) > 0)
		pa(a, b);
}

int	find_idx(t_list	*head, int nb)
{
	t_list	*temp;
	int		i;

	temp = head;
	i = 0;
	while (temp -> num != nb)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}
