/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:52 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 12:04:01 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(mlx_image_t *img, int max_it)
{
	int			y;
	int			x;
	int			it;
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
			it = 0;
	// Mandelbrot it
			while (num.zr * num.zr + num.zi * num.zi <= 4.0 && it < max_it)
			{
				num.tmp = num.zr * num.zr - num.zi * num.zi + num.real;
				num.zi = 2.0 * num.zr * num.zi + num.imag;
				num.zr = num.tmp;
				it++;
			}
	// Map it to color
			if (it == max_it)
			{
				color.red = 255;
				color.green = 0;
				color.blue = 0;
			}
			else
			{
				color.red = (255 * it) / max_it;
				color.green = (255 * it) / max_it;
				color.blue = 0;
			}
	// Combine into an RGBA color
			color.colrgba = combine_colours(color.red, color.green, color.blue);
			((uint32_t *)img->pixels)[y * img->width + x] = color.colrgba;
			set_pixel(img, x, y, color.colrgba);
			x++;
		}
		y++;
	}
}
