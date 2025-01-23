/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:32:45 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/23 12:50:33 by vsoulas          ###   ########.fr       */
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
