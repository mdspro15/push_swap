/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:22:19 by schiou            #+#    #+#             */
/*   Updated: 2023/03/20 15:36:36 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//n - number of bytes to be copied
//memcpy() doesn't check for overflow or \0
#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst1;
	const char	*src1;
	size_t		i;

	dst1 = dst;
	src1 = src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[20];

	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);
	ft_memcpy(dest, src, sizeof(src));
	printf("%s", dest);
	return (0);
}*/
