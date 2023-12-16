/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:09:48 by schiou            #+#    #+#             */
/*   Updated: 2023/11/30 10:20:39 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*new_b;
	t_list	*new_a;

	new_b = *head_a;
	new_a = *head_a;
	new_a = new_a -> next;
	if (*head_b == NULL)
	{
		new_b -> next = NULL;
		*head_b = new_b;
		*head_a = new_a;
	}
	else
	{
		new_b -> next = *head_b;
		*head_b = new_b;
		*head_a = new_a;
	}
	write(1, "pb\n", 3);
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*new_b;
	t_list	*new_a;

	new_b = *head_b;
	new_a = *head_b;
	new_b = new_b -> next;
	new_a -> next = *head_a;
	*head_a = new_a;
	*head_b = new_b;
	write(1, "pa\n", 3);
}
