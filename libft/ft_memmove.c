/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:24:06 by schiou            #+#    #+#             */
/*   Updated: 2023/03/21 19:23:32 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// len - number of bytes to be copied
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (!dst && !src)
		return (0);
	if (src < dst)
		while (len--)
			dst1[len] = src1[len];
	else
		while (len--)
			*dst1++ = *src1++;
	return (dst);
}
/*
int	main()
{
	char	src[20] = "abcdefghijk";
	ft_memmove(src, src + 3, 5);
	printf("memmove : %s\n", src);
	char	src1[8] = "hijklm";
	char	dest[10] = "abcdef";
	ft_memmove(dest, src1, 4);
	printf("Separete : %s", dest);
	//ft_memcpy(src + 3, src, 6);
	//printf("memcpy : %s", src);
	return (0);
}*/
