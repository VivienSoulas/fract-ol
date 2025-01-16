/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:36:14 by vsoulas          ###   ########.fr       */
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
	set_window(&fractol, argv[4]);
	return EXIT_SUCCESS;
}
