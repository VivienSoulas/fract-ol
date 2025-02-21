#include "fractol.h"

void	render_newton(mlx_image_t *img, t_fractol *fra, int max_it)
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
			n.it = calc_newton(max_it, n.r, n.i);
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

// Newton formula : z^3 − 2z + 2
// first calculate num.denominator (derivative of z^3 - 2z + 2): 3z^2 - 2
// then calculate numerator (z^3 - 2z + 2)
// then z = z - (z^3 - 2z + 2)/(3z^2 - 2)
// then check for convergence to a root
// int	calc_newton(int max_it, double real, double imag)
// {
// 	t_numbers	num;
// 	double		tr;
// 	double		num.tmp_i;
// 	double		num.denom;

// 	num.r = real;
// 	num.i = imag;
// 	num.it = 0;
// 	while (num.it < max_it)
// 	{
// 		num.dr = 3 * (num.r * num.r - num.i * num.i) - 2;
// 		num.di = 6 * num.r * num.i;
// 		tr = num.r * num.r * num.r - 3 * num.r * num.i * num.i - 2 * num.r + 2;
//num.tmp_i = 3 * num.r * num.r * num.i - num.i * num.i * num.i - 2 * num.i;
// 		num.denom = num.dr * num.dr + num.di * num.di;
// 		if (num.denom == 0.0)
// 			break ;
// 		num.r = num.r - (tr * num.dr + num.tmp_i * num.di) / num.denom;
// 		num.i = num.i - (num.tmp_i * num.dr - tr * num.di) / num.denom;
// 		if ((tr * tr + num.tmp_i * num.tmp_i) < 1e-6)
// 			break ;
// 		num.it++;
// 	}
// 	return (num.it);
// }

// p(z) = z^4 - 1
// Calculate z^4
// Numerator is z^4 - 1
// num.denominator is 4z^3
// Update z using Newton's method
// Check for convergence to a root

int	calc_newton(int max_it, double real, double imag)
{
	t_numbers	n;

	n.r = real;
	n.i = imag;
	n.it = 0;
	while (n.it < max_it)
	{
		n.z4_r = n.r * n.r * n.r * n.r - 6 * n.r * n.r * n.i * n.i + n.i
			* n.i * n.i * n.i;
		n.z4_i = 4 * n.r * n.r * n.r * n.i - 4 * n.r * n.i * n.i * n.i;
		n.tmp_r = n.z4_r - 1;
		n.tmp_i = n.z4_i;
		n.z3_r = n.r * n.r * n.r - 3 * n.r * n.i * n.i;
		n.z3_i = 3 * n.r * n.r * n.i - n.i * n.i * n.i;
		n.denom = 4 * (n.z3_r * n.z3_r + n.z3_i * n.z3_i);
		if (n.denom < 1e-6)
			break ;
		n.r = n.r - (n.tmp_r * n.z3_r + n.tmp_i * n.z3_i) / n.denom;
		n.i = n.i - (n.tmp_i * n.z3_r - n.tmp_r * n.z3_i) / n.denom;
		if ((n.tmp_r * n.tmp_r + n.tmp_i * n.tmp_i) < 1e-6)
			break ;
		n.it++;
	}
	return (n.it);
}
