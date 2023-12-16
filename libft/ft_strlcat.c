/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:22:08 by schiou            #+#    #+#             */
/*   Updated: 2023/03/22 15:29:13 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (i < dstsize - dst_len - 1 && src[i] != '\0')
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dst_len + src_len);
}
/*
int	main()
{
	char	dst[30] = "pqrs";
	char	*src = "abcdefghi";
	size_t	n;
	n = ft_strlcat(dst, src, 15);
	printf("%zu", n);
	return (0);
}*/
