/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:43:16 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/16 11:44:00 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Set a pixel in the image
void	set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	((uint32_t *)img->pixels)[y * img->width + x] = color;
}
