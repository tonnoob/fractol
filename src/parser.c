/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:25:25 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/27 12:38:03 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_num(char *str)
{
	int	i;
	int	has_dot;

	i = 0;
	has_dot = 0;
	if (ft_issignal(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && has_dot == 0)
				has_dot = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int parse_args(int ac, char **av, t_fractal *f)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		data_init(f, "Mandelbrot");
		return (1);
	}
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (!is_num(av[2]) || !is_num(av[3]))
			return (0);
		data_init(f, "Julia");
		f->julia_v.real = ft_atod(av[2]);
		f->julia_v.imag = ft_atod(av[3]);   
		return (1);
	}
	return (0);
}
