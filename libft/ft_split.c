/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:52:54 by schiou            #+#    #+#             */
/*   Updated: 2023/11/28 12:08:26 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	num_word(char const *s, char c);
static void	ft_fill_word(char **split, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len;

	len = num_word(s, c);
	split = (char **)ft_calloc(sizeof(char *), len + 1);
	if (!split)
		return (NULL);
	ft_fill_word(split, s, c);
	return (split);
}

static int	num_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}
/*
static void	*ft_free(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
*/

static void	ft_fill_word(char **split, char const *s, char c)
{
	size_t	i;
	int		start;
	int		is_word;
	int		n;

	i = 0;
	start = 0;
	is_word = 0;
	n = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && is_word == 0)
		{
			start = i;
			is_word = 1;
		}
		else if ((s[i] == c || s[i] == '\0') && is_word == 1)
		{
			split[n++] = ft_substr(s, start, i - start);
			is_word = 0;
		}
		i++;
	}
}
/*
int	main()
{
	char	*s = "Hello world !";
	char	**split;
	int	i = 0;
	split = ft_split(s, ' ');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}*/
