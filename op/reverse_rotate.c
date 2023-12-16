/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:07:52 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:08:05 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//bottom number to top, moving clockwise(right)
//last node would be first node
//last seconde node would be last node
t_list	*find_last_second(t_list *head);

void	reverse_rotate(t_list **head)
{
	t_list	*last;
	t_list	*lastsecond;

	last = *head;
	lastsecond = find_last_second(*head);
	while (last -> next != NULL)
		last = last -> next;
	last -> next = *head;
	lastsecond -> next = NULL;
	*head = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

t_list	*find_last_second(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp -> next -> next == NULL)
			break ;
		temp = temp -> next;
	}
	return (temp);
}
