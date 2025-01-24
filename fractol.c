/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/24 13:25:55 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 5)
	{
		ft_printf("Please indicate :\n");
		ft_printf("<max iteration> <width> <height> <fractal selection>\n");
		ft_printf("Mandelbrot <m> Julia 1 <j> Julia 2 <p> Julia 3 <o>\n");
		return (1);
	}
	fractol.arg = argv[4];
	if (check_arg(argv, &fractol) == 1)
	{
		ft_printf("Please indicate :\n");
		ft_printf("<max iteration> <width> <height> <fractal selection>\n");
		ft_printf("Mandelbrot <m> Julia 1 <j> Julia 2 <p> Julia 3 <o>\n");
		return (1);
	}
	initial_state(&fractol);
	fractol.max_it = ft_atoi(argv[1]);
	fractol.width = ft_atoi(argv[2]);
	fractol.height = ft_atoi(argv[3]);
	fractol.init_max = ft_atoi(argv[1]);
	set_window(&fractol);
	return (EXIT_SUCCESS);
}

int	check_arg(char **argv, t_fractol *fractol)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] && i < 4)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isnum(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	if ((ft_strcmp(fractol->arg, "m") == 0)
		|| (ft_strcmp(fractol->arg, "j") == 0)
		|| (ft_strcmp(fractol->arg, "o") == 0)
		|| (ft_strcmp(fractol->arg, "p") == 0))
		return (0);
	return (1);
}
