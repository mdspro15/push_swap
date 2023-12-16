/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:30:39 by schiou            #+#    #+#             */
/*   Updated: 2023/03/14 20:12:04 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//n - number of char to be searched
//Return NULL if char is not found 

//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		ch;

	ptr = s;
	ch = c;
	while (n--)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
/*
int	main()
{
	char	*s = "hello, world!";
	char	*result;
	result = ft_memchr(s, 'e', sizeof(s));
	printf("%s\n", result);
	result = ft_memchr(s, 'z', sizeof(s));
	printf("%s", result);
	return (0);
}*/
