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
	int			max_interations;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 3)
	{
		printf("invalid arguments\n");
		return (-1);
	}
	max_interations = 20;
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
	render_mandelbrot(img, max_interations);

// Display the image in the window
	mlx_image_to_window(mlx, img, 0, 0);

// Main loop
	mlx_loop(mlx);

// Cleanup
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return EXIT_SUCCESS;
}
