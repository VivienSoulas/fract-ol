 #include "fractol.h"
 
void render_mandelbrot(mlx_image_t *img, int max_iterations)
{
	int			y;
	int			x;
	int			iteration;
	double		real;
	double		imag;
	double		zr;
	double		zi;
	double		tmp;
	uint8_t		red, blue, green;
	uint32_t	color;

	y = 0;
	while (y < (int)img->height)
	{
		x = 0;
        while (x < (int)img->width)
        {
            // Map pixel (x, y) to complex plane between -2 and 2 with x on 0
            real = (x - img->width / 2.0) * 4.0 / img->width;
            imag = (y - img->height / 2.0) * 4.0 / img->width;

            zr = 0.0;
			zi = 0.0;
			iteration = 0;
            // Mandelbrot iteration
            while (zr * zr + zi * zi <= 4.0 && iteration < max_iterations)
            {
                tmp = zr * zr - zi * zi + real;
                zi = 2.0 * zr * zi + imag;
                zr = tmp;
                iteration++;
            }

            // Map iteration to color
			if (iteration == max_iterations)
			{
				red = 255;
				green = 0;
				blue = 0;
			}
			else
			{
				// red = 255;
				// green = 255;
				// blue = 0;
                red = (255 * iteration) / max_iterations;
                green = (255 * iteration) / max_iterations;
           		blue = 0;
			}
			// Combine into an RGBA color
			color = (red << 24) | (green << 16) | (blue << 8) | 0x00;
            ((uint32_t *)img->pixels)[y * img->width + x] = color;
			set_pixel(img, x, y, color);
			x++;
        }
		y++;
	}
}

// Set a pixel in the image
void set_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
		((uint32_t *)img->pixels)[y * img->width + x] = color;
}
