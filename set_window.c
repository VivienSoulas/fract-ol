/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:09:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 12:08:08 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_window(t_fractol *fractol, char *arg)
{
// Initialize MLX42
	fractol->engine.mlx = mlx_init(fractol->width, fractol->height, "MLX42 Image Example", true);
	if (!fractol->engine.mlx)
	{
		fprintf(stderr, "Failed to initialize MLX42\n");
		return (EXIT_FAILURE);
	}
// Create an image
	fractol->engine.win = mlx_new_image(fractol->engine.mlx, fractol->width, fractol->height);
	if (!fractol->engine.win)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(fractol->engine.mlx);
		return (EXIT_FAILURE);
	}
// render mandelbrot
	if (strcmp(arg, "m") == 0)
		render_mandelbrot(fractol->engine.win, fractol->max_it);
	else if (strcmp(arg, "j") == 0)
		render_julia(fractol->engine.win, fractol->max_it);
// Display the image in the window
	mlx_image_to_window(fractol->engine.mlx, fractol->engine.win, 0, 0);
// Main loop
	mlx_loop(fractol->engine.mlx);
// Cleanup
	mlx_delete_image(fractol->engine.mlx, fractol->engine.win);
	mlx_terminate(fractol->engine.mlx);
	return (EXIT_SUCCESS);
}
