/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:15 by vsoulas           #+#    #+#             */
/*   Updated: 2024/12/13 12:38:49 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}	t_engine;

void	mlx_initialisation(int width, int height);

void set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void render_mandelbrot(mlx_image_t *img, int max_iterations);

#endif