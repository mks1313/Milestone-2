/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:27:40 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/31 15:32:12 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_stack(t_stack **stack, char c)
{
	t_stack	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	ft_stkadd_back(stack, tmp);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	r_rboth(t_stack **a, t_stack **b)
{
	r_stack(a, ' ');
	r_stack(b, ' ');
	write(1, "rr\n", 3);
}

void	rr_stack(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*stack_tmp;

	stack_tmp = (*stack);
	while (stack_tmp->next->next)
		stack_tmp = stack_tmp->next;
	tmp = stack_tmp->next;
	stack_tmp->next = NULL;
	ft_stkadd_front(stack, tmp);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rr_rboth(t_stack **a, t_stack **b)
{
	rr_stack(a, ' ');
	rr_stack(b, ' ');
	write(1, "rrr\n", 4);
}
