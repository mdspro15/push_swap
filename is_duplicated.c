/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:41:38 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:12:47 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if there is duplicate node in linked list
//simple nested loop that iterates over each node in the linke list
//for each node,iterates over all the nodes that follow it.
int	is_duplicated(t_list *head)
{
	t_list	*temp;
	t_list	*ptr;

	temp = head;
	while (temp -> next != NULL)
	{
		ptr = temp -> next;
		while (ptr != NULL)
		{
			if (temp -> num == ptr -> num)
				return (1);
			ptr = ptr -> next;
		}
		temp = temp -> next;
	}
	return (0); 
}
