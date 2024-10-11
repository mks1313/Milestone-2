/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:16:55 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/11 19:09:23 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_input(int argc, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_and_exit();
		nbr = ft_atol(argv[i]);
		if (!is_in_range(nbr))
			error_and_exit();
		i++;
	}
}
