/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:20 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:09:57 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//swap 2 top elements in stack
void	swap(t_list *head)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	first = head;
	second = first -> next;
	temp = first -> num;
	first -> num = second -> num;
	second -> num = temp;
}

//swap 2 top element in stack A
void	sa(t_list *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

//swap 2 top element in stack B
void	sb(t_list *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
