/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:26:59 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/31 15:27:20 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stkadd_front(t_stack **stack, t_stack *new)
{
	new->next = (*stack);
	(*stack) = new;
}

void	ft_stkadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!(*stack))
	{
		(*stack) = new;
		return ;
	}
	if (new)
	{
		tmp = (*stack);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
