/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:58:28 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:12:21 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//exit(1) means exit failure
void	error_and_exit(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	exit(1);
}

void	free_list(t_list *head)
{
	t_list	*current;

	while (head != NULL)
	{
		current = head;
		head = head -> next;
		free(current);
	}
}

//loop through each row
//free memory allocated for the array of pointers
void	free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
