/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 04:16:48 by otton-sousa       #+#    #+#             */
/*   Updated: 2026/01/26 06:05:47 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_image		img;
	int			type;
	char		*name;
	t_complex	julia_v;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			max_iter;
	double		zoom;
	int			color_shift;
}	t_fractal;

#endif