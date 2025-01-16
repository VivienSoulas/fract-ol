/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:15 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:37:51 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include <string.h>

typedef struct s_engine
{
    void		*mlx;
    void		*window;
}	t_engine;

typedef struct s_fractol
{
	int			width;
	int			height;
	int			max_it;
	t_engine	engine;
}	t_fractol;

typedef struct s_colours
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint32_t	colour_rgba;
}	t_colours;

typedef struct s_numbers
{
	double		real;
	double		imag;
	double		zr;
	double		zi;
	double		tmp;
}	t_numbers;

void	mlx_initialisation(int width, int height);

void 	set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void 	render_mandelbrot(mlx_image_t *img, int max_it);
void	render_julia(mlx_image_t *img, int max_it);
int		set_window(t_fractol *fractol, char *arg);

#endif