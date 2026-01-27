/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:25:25 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/27 11:38:11 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int parse_args(int ac, char **av, t_fractal *f)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		data_init(f, "Mandelbrot");
		return (1);
	}
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		data_init(f, "Julia");
		f->julia_v.real = ft_atod(av[2]);
		f->julia_v.imag = ft_atod(av[3]);   
		return (1);
	}
	return (0);
}
