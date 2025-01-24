/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:47:22 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/24 17:54:47 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// max_it = max iteration
// init_max = initial max iteration
// c_x / c_y = center axe x / y
// colours unint8_t = red (r), green (g), blue (b)
// rgba = combined colours colours rgba
// cjr and cji = real and imag part of the const complex number c for julia
typedef struct s_fractol
{
	char		*arg;
	int			width;
	int			height;
	int			max_it;
	int			init_max;
	double		zoom;
	double		c_x;
	double		c_y;
	double		cjr;
	double		cji;
	mlx_image_t	*win;
	mlx_t		*mlx;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	rgba;
}	t_fractol;

// r = real part of the complex number
// i = imaginary part of the complex number
// x and y are for nested loop of fractal
// it = iteration
// w = width of the image depending on the zoom
typedef struct s_numbers
{
	double		r;
	double		i;
	double		tmp;
	int			y;
	int			x;
	int			it;
	int			w;
}	t_numbers;

int			check_arg(char **argv, t_fractol *fractol);
void		set_pixel(mlx_image_t *img, int x, int y, uint32_t color);
int			set_window(t_fractol *fra);
void		initial_state(t_fractol *fra);
void		acquisition(mlx_image_t *win, t_fractol *fractol);
void		render_mandelbrot(mlx_image_t *img, t_fractol *fractol, int max_it);
void		render_julia(mlx_image_t *img, t_fractol *fra, int max_it);
int			calc_mandelbrot(int max_it, double real, double imag);
int			calc_julia(int max_it, double real, double imag, t_fractol *fra);
uint32_t	c(int a, int b, int c);
void		scrollhook(double xdelta, double ydelta, void *param);
void		keyhook(mlx_key_data_t keydata, void *param);
void		handle_fractal_selection(mlx_key_data_t keydata, t_fractol *fra);
void		handle_iteration(mlx_key_data_t keydata, t_fractol *fra);
void		handle_reset(mlx_key_data_t keydata, t_fractol *fra);
void		handle_colours(mlx_key_data_t keydata, t_fractol *fra);
void		handle_moves(mlx_key_data_t keydata, t_fractol *fra);
void		rezise_callback(int32_t width, int32_t height, void *param);
void		close_window(t_fractol *fractol);
int			ft_atoi(char *str);
int			ft_strcmp(char *str1, char *str2);
int			ft_isnum(char c);

#endif