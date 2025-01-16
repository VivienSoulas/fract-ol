/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:05:27 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fractol.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vsoulas <vsoulas@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/06 14:53:18 by vsoulas		   #+#	#+#			 */
/*   Updated: 2024/12/13 13:20:22 by vsoulas		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int 		width;
	int 		height;
	int			max_it;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 4)
	{
		printf("Please indicate <length> <height>\n");
		printf("For Mandelbrot <m>\nFor Julia <j>\n");
		return (-1);
	}
	if (strcmp(argv[3], "m") != 0 && strcmp(argv[3], "j") != 0)
	{
		printf("Please indicate <m> for Mandelbrot or <j> for Julia\n");
		return (-1);
	}
	max_it = 20;
	width = atoi(argv[1]);
	height = atoi(argv[2]);
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
	return EXIT_SUCCESS;
}
