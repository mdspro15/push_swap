/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:33 by schiou            #+#    #+#             */
/*   Updated: 2023/03/15 17:06:12 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int	main()
{
	char	dst[5];
	char	*src = "Hello, world!";
	size_t	n;
	n = ft_strlcpy(dst, src, sizeof(dst));
	printf("%zu", n);
	return (0);
}*/
