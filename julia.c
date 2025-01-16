/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:00:39 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:44:50 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_julia(mlx_image_t *img, int max_it)
{
	int			y;
	int			x;
	int			iteration;
	t_numbers	num;
	t_colours	color;

	y = 0;
	while (y < (int)img->height)
	{
		x = 0;
		while (x < (int)img->width)
		{
	// Map pixel (x, y) to complex plane between -2 and 2 with x on 0
			num.real = (x - img->width / 2.0) * 4.0 / img->width;
			num.imag = (y - img->height / 2.0) * 4.0 / img->width;
			num.zr = 0.0;
			num.zi = 0.0;
			iteration = 0;
	// Mandelbrot iteration
			while (num.zr * num.zr + num.zi * num.zi <= 4.0 && iteration < max_it)
			{
				num.tmp = num.zr * num.zr - num.zi * num.zi + num.real;
				num.zi = 2.0 * num.zr * num.zi + num.imag;
				num.zr = num.tmp;
				iteration++;
			}
	// Map iteration to color
			if (iteration == max_it)
			{
				color.red = 0;
				color.green = 0;
				color.blue = 255;
			}
			else
			{
				color.red = (255 * iteration) / max_it;
				color.green = (255 * iteration) / max_it;
				color.blue = 255;
			}
	// Combine into an RGBA color
			color.colour_rgba = (color.red << 24) | (color.green << 16) | (color.blue << 8) | 0x00;
			((uint32_t *)img->pixels)[y * img->width + x] = color.colour_rgba;
			set_pixel(img, x, y, color.colour_rgba);
			x++;
		}
		y++;
	}
}
