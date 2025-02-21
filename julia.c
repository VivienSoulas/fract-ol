/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:52 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/06 14:26:10 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Map pixel (x, y) to complex plane between -2 and 2
// Mandelbrot pixels in the complex plane
// Map it to color
// Combine into an RGBA color
// fra = fractol, max_it = max iteration
// w = width of the image depending on the zoom
void	render_julia(mlx_image_t *img, t_fractol *fra, int max_it)
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
			n.it = calc_julia(max_it, n.r, n.i, fra);
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
// num.zr = real part of the complex number z in the formula z = z^2 + c
// this num.zr changes in each iteration
// c is a constant for Julia set
int	calc_julia(int max_it, double real, double imag, t_fractol *fra)
{
	t_numbers		num;

	num.it = 0.0;
	while (real * real + imag * imag <= 4.0 && num.it < max_it)
	{
		num.tmp = real * real - imag * imag + fra->cjr;
		imag = 2 * real * imag + fra->cji;
		real = num.tmp;
		num.it++;
	}
	return (num.it);
}
