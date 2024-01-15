/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:06:39 by schiou            #+#    #+#             */
/*   Updated: 2023/12/06 16:01:20 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_split(char **argv, t_list **head_a);
size_t	check_space(char *str);
long	check_atoi(char *str);

void	check_arg(int ac, char **argv, t_list **head_a)
{
	int	num;
	int	i;

	if (ac < 2)
		exit(1);
	else if (ac == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			error_and_exit("Error:Empty string!\n");
		if (ft_strlen(argv[1]) == check_space(argv[1]))
			error_and_exit("Error:There is non-digit character!\n");
		use_split(argv, head_a);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			num = check_atoi(argv[i]);
			ft_lst_add_back(head_a, ft_lstnew(num));
			i++;
		}
	}
}

size_t	check_space(char *str)
{
	int	i;
	int	count;
	while (str[i])
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			count++;
		i++;
	}
	return (count);
}

void	use_split(char **argv, t_list **head_a)
{
	char	**tmp;
	int		i;
	int		num;

	tmp = ft_split(argv[1], ' ');
	i = 0;
	while (tmp[i])
	{
		num = check_atoi(tmp[i]);
		ft_lst_add_back(head_a, ft_lstnew(num));
		i++;
	}
	free_2d(tmp);
}

long	check_atoi(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		error_and_exit("Error:There is non-digit character!\n");
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
		error_and_exit("Error:The number is not within the range of INT\n");
	return (num * sign);
}