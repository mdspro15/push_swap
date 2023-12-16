/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:54:57 by schiou            #+#    #+#             */
/*   Updated: 2023/11/30 12:00:36 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode -> num = num;
	newnode -> mark = 0;
	newnode -> pivot = 0;
	newnode -> next = NULL;
	return (newnode);
}

void	ft_lst_add_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last -> next != NULL)
		last = last -> next;
	last -> next = new;
}

int	ft_lstsize(t_list *head)
{
	int	count;

	count = 0;
	while (head != NULL && head -> mark == 0)
	{
		head = head -> next;
		count++;
	}
	return (count);
}