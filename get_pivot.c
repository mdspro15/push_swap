/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:38:12 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 11:06:27 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*copy_list(t_list *a, int size);
void	quicksort(int *arr, int left, int right);

int	get_pivot(t_list *a, int size)
{
	int	*arr;
	int	pivot;

	arr = copy_list(a, size);
	if (!arr)
		return (0);
	quicksort(arr, 0, size - 1);
	pivot = arr[size / 2];
	free(arr);
	return (pivot);
}

int	*copy_list(t_list *a, int size)
{
	int		*arr;
	int		i;
	t_list	*temp;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	temp = a;
	while (i < size)
	{
		arr[i] = temp -> num;
		i++;
		temp = temp -> next;
	}
	return (arr);
}

void	ft_swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	quicksort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = 0;
	j = right;
	pivot = arr[left];
	if (left >= right)
		return ;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (pivot < arr[j])
			j--;
		if (i >= j)
			break ;
		ft_swap(&arr[i], &arr[j]);
		i++;
		j--;
	}
	quicksort(arr, left, i - 1);
	quicksort(arr, j + 1, right);
}
