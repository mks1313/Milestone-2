/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:24:50 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/31 16:38:31 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while ((*a))
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
}

int	end_search(t_stack **a, int min)
{
	t_stack	*tmp;
	int		moves;
	int		moves2;

	tmp = (*a);
	moves = 0;
	while (tmp->number != min)
	{
		tmp = tmp->next;
		moves++;
	}
	moves2 = check_length(a) - moves;
	if (moves <= moves2)
		return (moves);
	else
		return (-moves2);
}

void	reorder(t_stack **a, int min, char c)
{
	int	move;

	move = end_search(a, min);
	if (move > 0)
	{
		while (--move >= 0)
			r_stack(a, c);
	}
	else
	{
		while (++move <= 0)
			rr_stack(a, c);
	}
}

void	complete_stack(t_parameters *p)
{
	int	tmp;
	int	move;

	reorder(&p->b, ft_max(&p->b), 'b');
	tmp = ft_last(&p->a);
	move = p->b->number;
	if (tmp > move)
		rr_stack(&p->a, 'a');
	else
		p_stack(&p->b, &p->a, 'a');
	tmp = ft_last(&p->a);
	move = ft_max(&p->a);
	while (check_length(&p->a) != p->length)
	{
		if (tmp > p->b->number && tmp != move)
		{
			rr_stack(&p->a, 'a');
			tmp = ft_last(&p->a);
		}
		else
			p_stack(&p->b, &p->a, 'a');
	}
	reorder(&p->a, ft_min(&p->a), 'a');
}
