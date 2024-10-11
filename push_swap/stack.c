/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:45:44 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/11 19:15:25 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_node(long value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		error_and_exit();
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack_node	*init_stack(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;
	long			value;

	stack_a = NULL;
	i = 0;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		new_node = create_node(value);
		if (!stack_a)
			stack_a = neew_node;
		else
		{
			current->next = new_node;
			neew_node->prev = current;
		}
		current = new_node;
		i++;
	}
	return (satck_a);
}
