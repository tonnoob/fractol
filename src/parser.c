/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:25:25 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/28 12:01:44 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_valid_number(char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	if (!str || !*str)
		return (0);
	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.' && has_dot == 0)
			has_dot = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

int	parse_args(int ac, char **av, t_fractal *f)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		data_init(f, "Mandelbrot");
		return (1);
	}
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (!is_valid_number(av[2]) || !is_valid_number(av[3]))
			return (0);
		data_init(f, "Julia");
		f->julia_v.real = ft_atod(av[2]);
		f->julia_v.imag = ft_atod(av[3]);
		return (1);
	}
	return (0);
}
