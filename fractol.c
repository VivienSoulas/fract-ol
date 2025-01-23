/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/23 11:13:16 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 5)
	{
		ft_printf("Please indicate");
		ft_printf("<max iteration> <width> <height> <fractal selection>\n");
		ft_printf("Fractal selection: Mandelbrot <m>\n Julia <j>\n");
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
