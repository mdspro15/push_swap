/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:17:14 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:43:41 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_and_rra(t_list **a, t_list **b, int size);

//count same pivot and returns numbers of same pivot
int	count_same_pivot(t_list *head, int p)
{
	t_list	*temp;
	int		num;

	temp = head;
	num = 0;
	while (temp != NULL)
	{
		if (temp -> pivot == p && temp -> mark == 0)
			num++;
		temp = temp -> next;
	}
	return (num);
}

//check if these 2 numbers are in ascending order
//if it alreday sorted, just do "ra" or "sa" before do "ra"
void	p_num_is_two(t_list **a, t_list **b, int p_num)
{
	if (p_num == 2 && b == NULL)
	{
		if ((*a)-> num > (*a)-> next -> num)
			sa(*a);
		while (p_num -- > 0)
		{
			(*a)-> mark = 1;
			ra(a);
		}
	}
}

//check if these 3 numbers are in ascending order
//if it is sorted, do "ra" or "pb" and sort in B
void	p_num_is_three(t_list **a, t_list **b, int p_num)
{
	//int	first;
	//int	second;
	//int	third;

	//first = (*a)-> num;
	//second = (*a)-> next -> num;
	//third = (*a)-> next -> next -> num;
	//if (first < second && second < third)
	//{
		//while (p_num-- > 0)
		//{
			//(*a)-> mark = 1;
			//ra(a);
		//}
	//}
	//else
	//{
		while (p_num-- > 0)
			pb(a, b);
		small_sort(b, 'b');
		push_a_sorted_num(a, b);
	//}
}

//get pivot within same pivot range
//if smaller than pivot, do "pb", or do "ra" and count times.
//do "rra" for times we did "ra"
//why? because there is sorted are in bottom of A
void	more_p_num(t_list **a, t_list **b, int p_num)
{
	//int	p;
	//int	ra_num;
	push_b_half(a, b, p_num);
	/*p = get_pivot(*a, p_num);
	ra_num = 0;
	while (p_num-- > 0)
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
	if (is_mark1_already(a))
		while (ra_num-- > 0)
			rra(a);
	*/

	if (ft_lstsize(*b) > 3)
		push_a_until_3(a, b);
	if (ft_lstsize(*b) <= 3)
	{
		small_sort(b, 'b');
		push_a_sorted_num(a, b);
	}
}