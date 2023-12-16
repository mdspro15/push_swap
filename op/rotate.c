/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:13 by schiou            #+#    #+#             */
/*   Updated: 2023/11/30 10:20:50 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//top number to bottom moving counterclockwise(left)
//first node would be last node
//second node would be first node

void	rotate(t_list **head)
{
	t_list	*last;
	t_list	*new;

	last = *head;
	last = last -> next;
	new = last;
	while (last -> next != NULL)
		last = last -> next;
	last -> next = *head;
	last -> next -> next = NULL;
	*head = new;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
