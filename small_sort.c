/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:47:51 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:03:24 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list **head, int ch)
{
	if (ch == 'a')
	{
		if (!is_sorted(*head))
		{
			if (ft_lstsize(*head) == 2)
				sa(*head);
			if (ft_lstsize(*head) == 3)
				sort_three_a(head);
		}
	}
	else if (ch == 'b')
	{
		if (!is_sorted(*head))
		{
			if (ft_lstsize(*head) == 2)
				sb(*head);
			if (ft_lstsize(*head) == 3)
				sort_three_b(head);
		}
	}
}

//For 3 numbers, there are 6 possible cases include (1,2,3).
//Needs only 1 or 2 actions depend on smallest number's position 
//and biggest number's position.
void	sort_three_a(t_list **a)
{
	int	first;
	int	second;

	first = (*a)-> num;
	second = (*a)-> next -> num;
	if (ft_min(*a) == first)
	{
		rra(a);
		sa(*a);
	}
	else if (ft_max(*a) == first)
	{
		ra(a);
		if (!is_sorted(*a))
			sa(*a);
	}
	else
	{
		if (ft_min(*a) == second)
			sa(*a);
		else
			rra(a);
	}
}

void	sort_three_b(t_list **b)
{
	int	first;
	int	second;

	first = (*b)-> num;
	second = (*b)-> next -> num;
	if (ft_min(*b) == first)
	{
		rrb(b);
		sb(*b);
	}
	else if (ft_max(*b) == first)
	{
		rb(b);
		if (!is_sorted(*b))
			sb(*b);
	}
	else
	{
		if (ft_min(*b) == second)
			sb(*b);
		else
			rrb(b);
	}
}
