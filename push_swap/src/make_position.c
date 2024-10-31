/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:26:45 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/31 16:19:48 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pos_a(t_algorithm_data *alg, t_parameters *param)
{
	if (alg->moves_a > 1)
	{
		while (alg->moves_a-- != 1)
			r_stack(&param->a, 'a');
	}
	else if (alg->moves_a < -1)
	{
		while (alg->moves_a++ != -1)
			rr_stack(&param->a, 'a');
	}
}

void	move_pos_b(t_algorithm_data *alg, t_parameters *param)
{
	if (alg->moves_b > 0)
	{
		while (alg->moves_b-- != 0)
			r_stack(&param->b, 'b');
	}
	else if (alg->moves_b < 0)
	{
		while (alg->moves_b++ != 0)
			rr_stack(&param->b, 'b');
	}
}

void	move_pos_together(t_algorithm_data *alg, t_parameters *param)
{
	if (alg->moves_a > 1 && alg->moves_b > 0)
	{
		while (alg->moves_b-- != 0 && alg->moves_a-- != 1)
		{
			r_rboth(&param->a, &param->b);
		}
		alg->moves_b++;
	}
	else if (alg->moves_a < -1 && alg->moves_b < 0)
	{
		while (alg->moves_b++ != 0 && alg->moves_a++ != -1)
			rr_rboth(&param->a, &param->b);
		alg->moves_b--;
	}
}

void	make_position(t_algorithm_data *alg, t_parameters *param)
{
	if ((param->b) == NULL)
	{
		p_stack(&param->a, &param->b, 'b');
		return ;
	}
	move_pos_together(alg, param);
	move_pos_a(alg, param);
	move_pos_b(alg, param);
	p_stack(&param->a, &param->b, 'b');
}
