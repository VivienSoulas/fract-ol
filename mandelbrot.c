/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:52 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 15:35:17 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Map pixel (x, y) to complex plane between -2 and 2
// Mandelbrot pixels in the complex plane
// Map it to color
// Combine into an RGBA color
// fra = fractol, max_it = max iteration
// w = width of the image depending on the zoom
void	render_mandelbrot(mlx_image_t *img, t_fractol *fra, int max_it)
{
	t_numbers	n;

	n.y = 0;
	while (n.y < (int)img->height)
	{
		n.x = 0;
		while (n.x < (int)img->width)
		{
			n.w = img->width * fra->zoom;
			n.r = ((n.x - img->width / 2.0) * 4.0 / n.w) + fra->c_x;
			n.i = ((n.y - img->height / 2.0) * 4.0 / n.w) + fra->c_y;
			n.it = calc_mandelbrot(max_it, n.r, n.i);
			if (n.it == max_it)
				fra->rgba = c(0, 0, 0);
			else
				fra->rgba = c(fra->r * n.it, fra->g * n.it, fra->b * n.it);
			set_pixel(img, n.x, n.y, fra->rgba);
			n.x++;
		}
		n.y++;
	}
}

// real = real part of the constant complex number c
// num.r = real part of the complex number z in the formula z = z^2 + c
// this num.zr changes in each iteration (aka z_real)
int	calc_mandelbrot(int max_it, double real, double imag)
{
	double			tmp;
	t_numbers		num;

	num.r = 0.0;
	num.i = 0.0;
	num.it = 0.0;
	tmp = 0.0;
	while (num.r * num.r + num.i * num.i <= 4.0 && num.it < max_it)
	{
		tmp = num.r * num.r - num.i * num.i + real;
		num.i = 2.0 * num.r * num.i + imag;
		num.r = tmp;
		num.it++;
	}
	return (num.it);
}
