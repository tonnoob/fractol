/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:24:46 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/24 06:24:47 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libftprintf/ft_printf/ft_printf.h"
# include "./libftprintf/libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_img		img;        
	int			type;
	char		*name;
	double		julia_real;
	double		julia_imag;
	double		x_min;
	double		x_max;
	double		y_min; 
	double		y_max;
	int			max_iter;
	double		zoom;
	int			color_shift;
}	t_fractal;


#endif