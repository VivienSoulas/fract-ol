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
// first calculate denominator (derivative of z^3 - 2z + 2): 3z^2 - 2
// then calculate numerator (z^3 - 2z + 2)
// then z = z - (z^3 - 2z + 2)/(3z^2 - 2)
// then check for convergence to a root
int	calc_newton(int max_it, double real, double imag)
{
	t_numbers	num;
	double		tr;
	double		tmp_i;
	double		denom;

	num.r = real;
	num.i = imag;
	num.it = 0;
	while (num.it < max_it)
	{
		num.dr = 3 * (num.r * num.r - num.i * num.i) - 2;
		num.di = 6 * num.r * num.i;
		tr = num.r * num.r * num.r - 3 * num.r * num.i * num.i - 2 * num.r + 2;
		tmp_i = 3 * num.r * num.r * num.i - num.i * num.i * num.i - 2 * num.i;
		denom = num.dr * num.dr + num.di * num.di;
		if (denom == 0.0)
			break ;
		num.r = num.r - (tr * num.dr + tmp_i * num.di) / denom;
		num.i = num.i - (tmp_i * num.dr - tr * num.di) / denom;
		if ((tr * tr + tmp_i * tmp_i) < 1e-6)
			break ;
		num.it++;
	}
	return (num.it);
}

// p(z) = z^4 - 1
// int calc_newton(int max_it, double real, double imag)
// {
//	 t_numbers num;
//	 double tmp_r, tmp_i;
//	 double denom;
//	 num.r = real;
//	 num.i = imag;
//	 num.it = 0;	
//	 while (num.it < max_it)
//	 {
//		 // Calculate z^4
//		 double z4_r = num.r * num.r * num.r * num.r - 
//					  6 * num.r * num.r * num.i * num.i + 
//					  num.i * num.i * num.i * num.i;
//		 double z4_i = 4 * num.r * num.r * num.r * num.i - 
//					  4 * num.r * num.i * num.i * num.i; 
//		 // Numerator is z^4 - 1
//		 tmp_r = z4_r - 1;
//		 tmp_i = z4_i;
//		 // Denominator is 4z^3
//		 double z3_r = num.r * num.r * num.r - 3 * num.r * num.i * num.i;
//		 double z3_i = 3 * num.r * num.r * num.i - num.i * num.i * num.i;
//		 denom = 4 * (z3_r * z3_r + z3_i * z3_i);	
//		 if (denom < 1e-6)
//			 break;
//		 // Update z using Newton's method
//		 num.r = num.r - (tmp_r * z3_r + tmp_i * z3_i) / denom;
//		 num.i = num.i - (tmp_i * z3_r - tmp_r * z3_i) / denom;
//		 // Check for convergence to a root
//		 if ((tmp_r * tmp_r + tmp_i * tmp_i) < 1e-6)
//			 break;
//		 num.it++;
//	 }
//	 return num.it;
// }