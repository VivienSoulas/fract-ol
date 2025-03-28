/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:09:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/21 15:56:34 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initialize MLX42
// Create an image
// Initialize the state of the variables
// Call acquisition which will render the fractal
// Display the image in the window
// Set the different hooks
int	set_window(t_fractol *fra)
{
	fra->mlx = mlx_init(fra->width, fra->height, "Fractal", true);
	if (!fra->mlx)
	{
		ft_printf("Failed to initialize MLX42\n");
		return (EXIT_FAILURE);
	}
	fra->win = mlx_new_image(fra->mlx, fra->width, fra->height);
	if (!fra->win)
	{
		ft_printf("Failed to create image\n");
		mlx_terminate(fra->mlx);
		return (EXIT_FAILURE);
	}
	initial_state(fra);
	acquisition(fra->win, fra);
	mlx_image_to_window(fra->mlx, fra->win, 0, 0);
	mlx_scroll_hook(fra->mlx, &scrollhook, fra);
	mlx_key_hook(fra->mlx, &keyhook, fra);
	mlx_resize_hook(fra->mlx, &rezise_callback, fra);
	mlx_loop(fra->mlx);
	close_window(fra);
	return (EXIT_SUCCESS);
}

void	initial_state(t_fractol *fra)
{
	fra->c_x = 0.0;
	fra->c_y = 0.0;
	fra->zoom = 1.0;
	fra->max_it = fra->init_max;
	fra->r = 0;
	fra->g = 0;
	fra->b = 0;
	fra->rgba = c(fra->r, fra->g, fra->b);
	ft_set_julia(fra);
}

void	acquisition(mlx_image_t *win, t_fractol *fractol)
{
	if (ft_strcmp(fractol->arg, "m") == 0)
		render_mandelbrot(win, fractol, fractol->max_it);
	else if (ft_strcmp(fractol->arg, "j") == 0)
		render_julia(win, fractol, fractol->max_it);
	else if (ft_strcmp(fractol->arg, "p") == 0)
		render_julia(win, fractol, fractol->max_it);
	else if (ft_strcmp(fractol->arg, "o") == 0)
		render_julia(win, fractol, fractol->max_it);
	else if (ft_strcmp(fractol->arg, "i") == 0)
		render_julia(win, fractol, fractol->max_it);
	else if (ft_strcmp(fractol->arg, "n") == 0)
		render_newton(win, fractol, fractol->max_it);
}

void	close_window(t_fractol *fractol)
{
	if (fractol->win)
	{
		ft_printf("Closing window\n");
		mlx_delete_image(fractol->mlx, fractol->win);
		fractol->win = NULL;
	}
	if (fractol->mlx)
	{
		ft_printf("Terminating MLX42\n");
		mlx_terminate(fractol->mlx);
		fractol->mlx = NULL;
	}
	exit(0);
}

void	ft_set_julia(t_fractol *fra)
{
	if (ft_strcmp(fra->arg, "j") == 0)
	{
		fra->cjr = -0.8;
		fra->cji = 0.156;
	}
	else if (ft_strcmp(fra->arg, "p") == 0)
	{
		fra->cjr = -0.70176;
		fra->cji = 0.3842;
	}
	else if (ft_strcmp(fra->arg, "o") == 0)
	{
		fra->cjr = 0.4;
		fra->cji = -0.4;
	}
	if (ft_strcmp(fra->arg, "i") == 0)
	{
		fra->cjr = -0.123;
		fra->cji = 0.745;
	}
}
