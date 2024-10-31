/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:26:30 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/31 16:38:20 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int num)
{
	num = -1;
	write(2, "Error\n", 6);
	exit(num);
}

int	ft_len(char *s)
{
	int	i;

	if (!*s)
		return (20);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 12) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -sign;
	}
	while (*str)
	{
		if (((num * sign) <= INT_MAX && (num * sign) >= INT_MIN)
			&& (*str >= '0' && *str <= '9'))
			num = (num * 10) + (*str++ - '0');
		else
			return (0);
	}
	if ((num * sign) == INT_MIN)
		return (INT_MIN);
	return ((int)num * sign);
}
