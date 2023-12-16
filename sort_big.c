/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:56:33 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:56:14 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_is_min(t_list **a, t_list **b, int ch);

void	sort_big(t_list **a, t_list **b)
{
	int	first_p;
	int	p_num;
	int	size;
	
	while (first_is_min(a, b, 'a'))
		;
	size = ft_lstsize(*a);
	push_b_half(a, b, size);
	push_a_until_3(a, b);
	small_sort(b, 'b');
	push_a_sorted_num(a, b);
	while (!is_all_sorted(*a, *b))
	{
		while (first_is_min(a, b, 'a'))
			;
		first_p = (*a)-> pivot;
		p_num = count_same_pivot(*a, first_p);
		/*if (p_num == 1 && b == NULL)
		{
			(*a)-> mark = 1;
			ra(a);
		}*/
		if (p_num == 2 && b == NULL)
			p_num_is_two(a, b, p_num);
		else if (p_num == 3 && b == NULL)
			p_num_is_three(a, b, p_num);
		else
			more_p_num(a, b, p_num);
	}
}

//Get pivot from A
//If number is smaller than pivot, push to B
//Otherwise do ra as well as update each node's pivot
//This function can divide into 2 chunks
//It  means stack A contains big numbers of chunk
//and stack B contatins small numbers of chunk
void	push_b_half(t_list **a, t_list **b, int size)
{
	//int	size;
	int	p;
	int	ra_num;

	
	//size = ft_lstsize(*a);
	ra_num = 0;
	p = get_pivot(*a, size);
	while (size-- > 0)
	{
		if ((*a)-> num <= p && (*a)-> mark == 0)
			pb(a, b);
		else
		{
			(*a)-> pivot = p;
			ra(a);
			ra_num++;
		}
	}
	if (is_mark1_already(*a))
	{
		while (ra_num-- > 0)
			rra(a);
	}
}
/*
void	pb_and_rra(t_list **a, t_list **b, int size)
{
	int	p;
	int	ra_num;

	p = get_pivot(*a, size);
	while (size-- > 0)
	{
		if ((*a)-> num <= p && (*a)-> mark ==0)
			pb(a, b);
		else
		{
			(*a)-> pivot = p;
			ra(a);
			ra_num++;
		}
	}
	if (is_mark1_already(*a))
	{
		while (ra_num-- > 0)
			rra(a);
	}
}*/

//Get pivot from B
//If number is bigger than pivot, push to A as well as update each node's pivot
//If number is smaller than pivot, do "rb"
//We keep doing this until 3 numbers left in B
//This is the way we can pile up big chunk to small chunk
void	push_a_until_3(t_list **a, t_list **b)
{
	int	p;
	int	size;

	while (ft_lstsize(*b) > 3)
	{
		while (first_is_min(a, b, 'b'))
			;
		p = get_pivot(*b, ft_lstsize(*b));
		size = ft_lstsize(*b);
		while (size-- > 0)
		{
			if ((*b)-> num > p)
			{
				(*b)-> pivot = p;
				pa(a, b);
			}
			else
				rb(b);
		}
	}
}

//After small number is B are sorted, 
//update its node's mark, push to A and do "ra".
//It means we store sorted number in bottom of stack A.
void	push_a_sorted_num(t_list **a, t_list **b)
{
	if (is_sorted(*b))
	{
		while (ft_lstsize(*b) > 0)
		{
			(*b)-> mark = 1;
			pa(a, b);
			ra(a);
		}
	}
}

int	first_is_min(t_list **a, t_list **b, int ch)
{
	if (ch == 'a')
	{
		if ((*a)-> num == ft_min(a))
		{
			(*a)-> mark = 1;
			ra(a);
			return (1);
		}
		return (0);
	}
	else
	{
		if ((*b)-> num == ft_min(b))
		{
			(*b)-> mark = 1;
			pa(a, b);
			ra(a);
			return (1);
		}
		return (0);
	}
	return (0);
}

int	is_mark1_already(t_list *head)
{
	t_list *temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp -> mark == 1)
			return (1);
		temp = temp -> next;
	}
	return (0);
}