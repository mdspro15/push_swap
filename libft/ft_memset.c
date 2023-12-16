/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:42:40 by schiou            #+#    #+#             */
/*   Updated: 2023/03/15 19:43:50 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// len - number of bytes to be filled
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = b;
	ch = c;
	while (len--)
		*ptr++ = ch;
	return (b);
}
/*
int	main(void)
{
	char	str[] = "Hello, world!";
	char	dst[] = "Hello, world!";
	char	*result;
	dst = strcpy(dst, str);
	printf("%s, 'A', 5\n", str);
	result = memset(dst, 'A', 5);
	printf("Real memset : %s\n", result);
	
	printf("%s, 'A', 5\n", str);
	result = ft_memset(str, 'A', 5);
	printf("My memset : %s", result);
	return (0);
}*/
