/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:24:46 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/28 23:47:15 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/libftprintf/libft/libft.h"
# include "../libs/libftprintf/ft_printf/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "defines.h"
# include "structs.h"

void	init_viewport(t_fractal *f);
void	data_init(t_fractal *f, char *name);
void	fractal_init(t_fractal *f);
int		error_exit(char *msg);
void	window_init(t_fractal *f);
double	map(double norm, double out_min, double out_max);
void	fractal_render(t_fractal *f);
int		fractal_iter(t_complex z, t_complex c, int max_iter);
int		parse_args(int ac, char **av, t_fractal *f);
int		close_handler(t_fractal *f);
int		mouse_handler(int button, int x, int y, t_fractal *f);
int		esc_handler(int button, t_fractal *f);
int		get_color(int iter, int max_iter);
void	print_usage(void);
double	normalize(double value, double min, double max);

#endif