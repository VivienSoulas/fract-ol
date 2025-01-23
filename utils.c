/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:43:16 by vsoulas           #+#    #+#             */
/*   Updated: 2025/01/17 14:55:28 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// combine colours into an RGBA color
uint32_t	c(int a, int b, int c)
{
	t_fractol	color;

	color.rgba = (a << 0) | (b << 8) | (c << 16) | (0xFF << 24);
	return (color.rgba);
}

// Set a pixel in the image
void	set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	((uint32_t *)img->pixels)[y * img->width + x] = color;
}
