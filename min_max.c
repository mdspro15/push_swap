/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:29:38 by schiou            #+#    #+#             */
/*   Updated: 2023/11/30 14:29:59 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *head)
{
	t_list	*temp;
	int		min;

	temp = head;
	min = temp -> num;
	while (temp != NULL && temp -> mark == 0)
	{
		if (min > temp -> num)
			min = temp -> num;
		temp = temp -> next;
	}
	return (min);
}

int	ft_max(t_list *head)
{
	t_list	*temp;
	int		max;

	temp = head;
	max = temp -> num;
	while (temp != NULL)
	{
		if (max < temp -> num)
			max = temp -> num;
		temp = temp -> next;
	}
	return (max);
}
