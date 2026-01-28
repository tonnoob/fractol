/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:25:15 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/28 12:13:25 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void put_pixel_to_img(t_fractal *f, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * f->img.line_len) + (x * (f->img.bpp / 8));
	dst = f->img.pixels_ptr + offset;
	*(unsigned int *)dst = color;
}

static int calculate_pixel(t_fractal *f, int px, int py)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			color;

	c.real = map(normalize(px, 0, WIDTH), f->x_min, f->x_max);
	c.imag = map(normalize(py, 0, HEIGHT), f->y_max, f->y_min);
	iter = 0;
	if (f->type == MANDELBROT)
	{
		z.real = 0;
		z.imag = 0;
		iter = fractal_iter(z, c, MAX_ITER); 
	}
	if (f->type == JULIA)
	{
		z.real = c.real;
		z.imag = c.imag;
		c.real = f->julia_v.real;
		c.imag = f->julia_v.imag;
		iter = fractal_iter(z, c, MAX_ITER);
	}
	color = get_color(iter, f->max_iter);
	return (color);
}

void fractal_render(t_fractal *f)
{
	int py;
	int px;
	int color;

	py = 0;
	while (py < HEIGHT)
	{
		px = 0;
		while (px < WIDTH)
		{
			color = calculate_pixel(f, px, py);
			put_pixel_to_img(f, px, py, color);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}
