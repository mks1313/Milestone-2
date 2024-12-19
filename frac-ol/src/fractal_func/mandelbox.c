/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:52:20 by mmarinov          #+#    #+#             */
/*   Updated: 2024/12/19 15:17:24 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	box_wrap(double coord)
{
	if (coord > 1)
		coord = 2 - coord;
	else if (coord < -1)
		coord = -2 - coord;
	return (coord);
}

static double	radius_adjust(double min_radius, double magnitude)
{
	if (magnitude < min_radius)
		magnitude = magnitude / (min_radius * min_radius);
	else if (magnitude < 1)
		magnitude = 1 / (magnitude * magnitude);
	return (magnitude);
}

int	mandelbox(t_fractol *f_params, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		vr = f_params->fx * box_wrap(vr);
		vi = f_params->fx * box_wrap(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * f_params->sx * radius_adjust(f_params->rx, mag) + cr;
		vi = vi * f_params->sx * radius_adjust(f_params->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
