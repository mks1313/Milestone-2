/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:09:36 by mmarinov          #+#    #+#             */
/*   Updated: 2024/12/09 11:01:35 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double real, double imag, int max_iterations)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		iter;

	z_real = 0;
	z_imag = 0;
	iter = 0;
	while (z_real * z_imag + z_imag * z_imag <= 4 && iter < max_iterations)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
		iter++;
	}
	return (iter); // retornamos el numero de iteraciones.
}

int	get_color(int iter, int max_iterations)
{
	if (iter == max_iterations)
		return (0x000000); // Negro para puntos dentro del conjunto
	return (0xFFFFFF * iter) / max_iterations; // Escala de grises fuera del conjunto.
}
