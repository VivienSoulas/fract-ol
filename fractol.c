/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/23 10:53:57 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 5)
	{
		ft_printf("Please indicate <max iteration> <length> <height>\n");
		ft_printf("For Mandelbrot <m>\nFor Julia <j>\n");
		return (-1);
	}
	if (ft_strcmp(argv[4], "m") != 0 && ft_strcmp(argv[4], "j") != 0)
	{
		ft_printf("Please indicate <m> for Mandelbrot or <j> for Julia\n");
		return (-1);
	}
	initial_state(&fractol);
	fractol.max_it = ft_atoi(argv[1]);
	fractol.width = ft_atoi(argv[2]);
	fractol.height = ft_atoi(argv[3]);
	fractol.init_max = ft_atoi(argv[1]);
	fractol.arg = argv[4];
	set_window(&fractol);
	return (EXIT_SUCCESS);
}
