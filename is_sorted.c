/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:13:09 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 10:47:38 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if stack is sorted in ascending order.
//traverse linked list from head to end and compare with next node.
int	is_sorted(t_list *head)
{
	t_list	*temp;

	temp = head;
	if (temp == NULL)
		return (1);
	while (temp -> next != NULL)
	{
		if (temp -> num > temp -> next -> num)
			return (0);
		temp = temp -> next;
	}
	return (1);
}

int	is_all_sorted(t_list *a, t_list *b)
{
	if (is_sorted(a) && b == NULL)
		return (1);
	return (0);
}
