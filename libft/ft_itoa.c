/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:31:23 by schiou            #+#    #+#             */
/*   Updated: 2023/08/25 19:57:41 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	int_len(long nb);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;
	long	nb;

	nb = n;
	len = int_len(n);
	res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	i = len - 1;
	while (nb != 0)
	{
		res[i--] = ((nb % 10) + 48);
		nb = nb / 10;
	}
	return (res);
}

static int	int_len(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
/*
static char	*pre_fill(int len)
{
	char	*temp;

	temp = ft_calloc((len + 1), sizeof(char));
	if (!temp)
		return (NULL);
	return (temp);
}*/
