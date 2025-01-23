/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:12:20 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/23 12:50:12 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_fractal_selection(mlx_key_data_t keydata, t_fractol *fra)
{
	if (keydata.key == MLX_KEY_J)
	{
		fra->arg = "j";
		ft_printf("Julia preset 1\n");
		initial_state(fra);
	}
	else if (keydata.key == MLX_KEY_M)
	{
		fra->arg = "m";
		ft_printf("Mandelbrot\n");
		initial_state(fra);
	}
	else if (keydata.key == MLX_KEY_P)
	{
		fra->arg = "p";
		ft_printf("Julia preset 2\n");
		initial_state(fra);
	}
	else if (keydata.key == MLX_KEY_O)
	{
		fra->arg = "o";
		ft_printf("Julia preset 3\n");
		initial_state(fra);
	}
}

void	handle_iteration(mlx_key_data_t keydata, t_fractol *fra)
{
	if (keydata.key == MLX_KEY_W)
	{
		fra->max_it += 5;
		ft_printf("max iteration = %i\n", fra->max_it);
	}
	else if (keydata.key == MLX_KEY_S && fra->max_it > 5)
	{
		fra->max_it -= 5;
		ft_printf("max iteration = %i\n", fra->max_it);
	}
}

void	handle_reset(mlx_key_data_t keydata, t_fractol *fra)
{
	if (keydata.key == MLX_KEY_R)
	{
		ft_printf("Reset\n");
		initial_state(fra);
	}
}

void	handle_colours(mlx_key_data_t keydata, t_fractol *fra)
{
	if (keydata.key == MLX_KEY_T)
	{
		ft_printf("Red = %i\n", fra->r);
		fra->r += 10;
	}
	else if (keydata.key == MLX_KEY_G)
	{
		ft_printf("Green = %i\n", fra->g);
		fra->g += 10;
	}
	else if (keydata.key == MLX_KEY_B)
	{
		ft_printf("Blue = %i\n", fra->b);
		fra->b += 10;
	}
}

void	handle_moves(mlx_key_data_t keydata, t_fractol *fra)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		ft_printf("Move left\n");
		fra->c_x -= 1 / fra->zoom;
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		ft_printf("Move right\n");
		fra->c_x += 1 / fra->zoom;
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		ft_printf("Move down\n");
		fra->c_y += 1 / fra->zoom;
	}
	else if (keydata.key == MLX_KEY_UP)
	{
		ft_printf("Move up\n");
		fra->c_y -= 1 / fra->zoom;
	}
}
