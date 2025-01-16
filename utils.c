/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:43:16 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 12:09:49 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Set a pixel in the image
void	set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	((uint32_t *)img->pixels)[y * img->width + x] = color;
}

uint32_t	combine_colours(uint8_t red, uint8_t green, uint8_t blue)
{
	t_colours	color;

	color.colrgba = (red << 24) | (green << 16) | (blue << 8) | 0x00;
	return (color.colrgba);
}


// TODO
// atoi, strcmp, printf