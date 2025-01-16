/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:17:09 by vsoulas          ###   ########.fr       */
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
	t_fractol	fractol;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 5)
	{
		printf("Please indicate <max iteration> <length> <height>\n");
		printf("For Mandelbrot <m>\nFor Julia <j>\n");
		return (-1);
	}
	if (strcmp(argv[4], "m") != 0 && strcmp(argv[4], "j") != 0)
	{
		printf("Please indicate <m> for Mandelbrot or <j> for Julia\n");
		return (-1);
	}
	fractol.max_it = atoi(argv[1]);
	fractol.width = atoi(argv[2]);
	fractol.height = atoi(argv[3]);
	if (strcmp(argv[4], "m") == 0)
	{
		//set_window(mlx, img, fractol.width, fractol.height);
// Initialize MLX42
	mlx = mlx_init(fractol.width, fractol.height, "MLX42 Image Example", true);
	if (!mlx)
	{
		fprintf(stderr, "Failed to initialize MLX42\n");
		return EXIT_FAILURE;
	}
// Create an image
	img = mlx_new_image(mlx, fractol.width, fractol.height);
	if (!img)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(mlx);
		return EXIT_FAILURE;
	}
// render mandelbrot
		render_mandelbrot(img, fractol.max_it);
// Display the image in the window
		mlx_image_to_window(mlx, img, 0, 0);
// Main loop
		mlx_loop(mlx);
// Cleanup
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	}
	else if (strcmp(argv[4], "j") == 0)
	{
		
	}
	return EXIT_SUCCESS;
}
