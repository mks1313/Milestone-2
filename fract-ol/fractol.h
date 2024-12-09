/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:54:50 by mmarinov          #+#    #+#             */
/*   Updated: 2024/12/07 16:34:39 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_fractol
{
	void	*mlx;        //puntero a la conexion mlx
	void	*window;     //puntero a la ventana
	void	*img;        //Puntero a la imagen
	char	*data;       //Puntroa los datos de la imagen
	int		bpp;         //Bits por pixel
	int		line_size;   //Tamano de la linea de la imagen
	int		endian;      //Endian(formato de almacenamiento)
	int		height;      //ancho de la ventana
	int		width;       //alto de la ventana
	 // Variables de; fractal
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	int		max_iterations;
}	t_fractol;

// Funciones de Maldenbrot
int	mandelbrot(double real, double imag, int max_iterations);
int	get_color(int iter, int max_iterations);

# endif
