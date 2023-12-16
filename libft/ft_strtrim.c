/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:46:48 by schiou            #+#    #+#             */
/*   Updated: 2023/03/22 15:46:12 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (ft_strlen(set) == 0 && ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[start]) && s1[start] != '\0')
		start++;
	while (to_trim(set, s1[end - 1]) && end > start)
		end--;
	res = (char *)malloc (sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
/*
int	main()
{
	char	*s1 = "";
	char	*set = "cdef";
	char	*res;
	res = ft_strtrim(s1, set);
	return (0);
}*/
