/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:53:29 by schiou            #+#    #+#             */
/*   Updated: 2023/03/20 12:59:48 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	//char *string1 = "ha! needle in a haystack";
	//char *string2 = "hay";
	char *string1 = "lorem ipsum dolor sit amet";
	char *string2 = "ipsumm";
	size_t s = 30;
	char *result;
	
	result = ft_strnstr(string1, string2,  s);
	printf("yours:%s\n", result);
	result = strnstr(string1, string2, s);
	printf("clib's:%s", result);

	return (0);
}
*/
