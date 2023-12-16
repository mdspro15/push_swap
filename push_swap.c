/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:17:07 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 15:50:26 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	check_arg(ac, argv, &a);
	if (is_duplicated(a))
	{
		free_list(a);
		error_and_exit("Error:There is duplicate number!\n");
	}
	if (is_all_sorted(a, b))
	{
		free_list(a);
		exit(0);
	}
	
	if (!is_sorted(a))
		sort(&a, &b);
	if (is_all_sorted(a, b))
	{
		free_list(a);
		exit(0);
	}
	return (0);
}