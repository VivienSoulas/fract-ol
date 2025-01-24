/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:32:45 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/24 17:54:41 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fra;

	(void)xdelta;
	fra = param;
	if (ydelta > 0)
	{
		ft_printf("Zoom in\n");
		fra->zoom *= 2;
	}
	else if (ydelta < 0)
	{
		ft_printf("Zoom out\n");
		fra->zoom /= 2;
	}
	acquisition(fra->win, fra);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fra;

	fra = param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_window(fra);
	else
	{
		handle_fractal_selection(keydata, fra);
		handle_iteration(keydata, fra);
		handle_reset(keydata, fra);
		handle_colours(keydata, fra);
		handle_moves(keydata, fra);
	}
	acquisition(fra->win, fra);
}

void	rezise_callback(int32_t width, int32_t height, void *param)
{
	t_fractol	*fra;

	fra = param;
	fra->width = width;
	fra->height = height;
	ft_printf("Window resized to: %d x %d\n", width, height);
	mlx_delete_image(fra->mlx, fra->win);
	fra->win = mlx_new_image(fra->mlx, fra->width, fra->height);
	if (!fra->win)
	{
		ft_printf("Failed to create image\n");
		mlx_terminate(fra->mlx);
		exit(EXIT_FAILURE);
	}
	acquisition(fra->win, fra);
	mlx_image_to_window(fra->mlx, fra->win, 0, 0);
}
