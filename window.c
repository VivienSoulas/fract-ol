/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:09:17 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:10:07 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// Initialize MLX42
	mlx = mlx_init(width, height, "MLX42 Image Example", true);
	if (!mlx)
	{
		fprintf(stderr, "Failed to initialize MLX42\n");
		return EXIT_FAILURE;
	}
// Create an image
	img = mlx_new_image(mlx, width, height);
	if (!img)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(mlx);
		return EXIT_FAILURE;
	}
// render mandelbrot
		render_mandelbrot(img, max_it);
// Display the image in the window
		mlx_image_to_window(mlx, img, 0, 0);
// Main loop
		mlx_loop(mlx);
// Cleanup
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);