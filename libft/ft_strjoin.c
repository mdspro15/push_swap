/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:22:09 by schiou            #+#    #+#             */
/*   Updated: 2023/03/13 19:49:49 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*newstr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
		newstr[j++] = s1[i++];
	i = 0;
	while (i < s2_len)
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}
/*
int	main()
{
	char	*s1 = "Hello,";
	char	*s2 = "world!";
	char	*new;
	new = ft_strjoin(s1, s2);
	printf("%s", new);
	return (0);
}*/
