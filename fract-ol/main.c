/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:35:41 by mmarinov          #+#    #+#             */
/*   Updated: 2024/12/07 16:45:00 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fractol.h"

int	main(void)
{
	int		i;
	int		j;
	t_fractol fractol;

	i = 0;
	fractol.mlx = mlx_init();
	fractol.width = 800;
	fractol.height = 600;
	fractol.window = mlx_new_window(fractol.mlx, fractol.width, fractol.height, "Frct'ol - Maldenbrot");
	fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
	fractol.data = mlx_get_data_addr(fractol.img, &fractol.bpp, &fractol.line_size, &fractol.endian);
	fractol.min_real = -2.0;
	fractol.max_real = 1.0;
	fractol.min_imag = -1.5;
	fractol.max_imag = fractol.min_imag + (fractol.max_real - fractol.min_real) * fractol.height / fractol.width;
	fractol.max_iterations = 100;
	while (i < fractol.width)
	{
		j = 0;
		while (j < fractol.height)
		{
			double real = fractol.min_real + (i * (fractol.max_real - fractol.min_real) / fractol.width);
			double imag = fractol.min_imag + (j * (fractol.max_imag - fractol.min_imag) / fractol.height);
			// calculamos cuantas iteraciones se necesita para escapar
			int iter = mandelbrot(real, imag, fractol.max_iterations);
			// obtenemos el color basado en el numero de iters
			int color = get_color(iter, fractol.max_iterations);
			// asignamos el color al pixel (i. j)
			*(int *)(fractol.data + (i + j * fractol.width) * 4) = color;
			j++;
		}
		i++;
	}
	// renderizar imagen
	mlx_put_image_to_window(fractol.mlx, fractol.window, fractol.img, 0, 0);
	mlx_loop(fractol.mlx);
	return (0);
}
