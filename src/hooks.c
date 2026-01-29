/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 04:02:06 by otton-sousa       #+#    #+#             */
/*   Updated: 2026/01/29 00:07:17 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img.img_ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = map(normalize(x, 0, WIDTH), f->x_min, f->x_max);
	mouse_im = map(normalize(y, 0, HEIGHT), f->y_max, f->y_min);
	zoom_factor = 1.1;
	if (button == MOUSE_WHEEL_UP)
	{
		f->x_min = mouse_re + (f->x_min - mouse_re) / zoom_factor;
		f->x_max = mouse_re + (f->x_max - mouse_re) / zoom_factor;
		f->y_min = mouse_im + (f->y_min - mouse_im) / zoom_factor;
		f->y_max = mouse_im + (f->y_max - mouse_im) / zoom_factor;
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		f->x_min = mouse_re + (f->x_min - mouse_re) * zoom_factor;
		f->x_max = mouse_re + (f->x_max - mouse_re) * zoom_factor;
		f->y_min = mouse_im + (f->y_min - mouse_im) * zoom_factor;
		f->y_max = mouse_im + (f->y_max - mouse_im) * zoom_factor;
	}
	fractal_render(f);
	return (0);
}

int	esc_handler(int button, t_fractal *f)
{
	if (button == KEY_ESC)
		close_handler(f);
	return (EXIT_SUCCESS);
}
