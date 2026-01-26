/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:18:25 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/26 06:53:20 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void init_viewport(t_fractal *f)
{
	if (f->type == MANDELBROT)
	{
		f->x_min = -2.5;
		f->x_max = 1.0;
		f->y_min = -1.5;
		f->y_max = 1.5;
	}
	else if (f->type == JULIA)
	{
		f->x_min = -2.0;
		f->x_max = 2.0;
		f->y_min = -2.0;
		f->y_max = 2.0;
	}
}

void data_init(t_fractal *f, char *name)
{
	f->name = name;

	if (ft_strcmp(name, "mandelbrot") == 0)
		f->type = MANDELBROT;
	else if (ft_strcmp(name, "julia") == 0)
		f->type = JULIA;
	f->max_iter = MAX_ITER;
	f->zoom = 1.0;
	f->color_shift = 0;
	init_viewport(f);
}

void fractal_init(t_fractal *f)
{
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx, f->win);
		free(f->mlx);
		error_exit("Error: Failed to create image");
	}
	f->img.pixels_ptr = mlx_get_data_addr(
		f->img.img_ptr,
		&f->img.bpp,
		&f->img.line_len,
		&f->img.endian
	);
	if (!f->img.pixels_ptr)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		mlx_destroy_window(f->mlx, f->win);
		free(f->mlx);
		error_exit("Error: Failed to access the buffer");
	}
}

void	window_init(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		error_exit("Error: MLX did not initialize");
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	if (!f->win)
	{
		free(f->mlx);
		error_exit("Error: I couldn't open the window.");
	}
}
