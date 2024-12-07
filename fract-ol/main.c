/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:35:41 by mmarinov          #+#    #+#             */
/*   Updated: 2024/12/05 13:43:12 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

int	main()
{
	void	*mlx;
	void	*window;
	int	i = 0, j = 0;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "Frct'ol - Maldenbrot");

	// Painting screen ->
	while (i <= 800)
	{
		j = 0;
		while (j <= 600)
		{	
			mlx_pixel_put(mlx, window, i, j, 0x00FF00);
			j++;
		}
		i++;
	}

	// LOOP
	mlx_loop(mlx);

	return (0);
}
