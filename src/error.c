/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 04:40:54 by otton-sousa       #+#    #+#             */
/*   Updated: 2026/01/26 04:43:01 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void print_usage(void)
{
	ft_putstr_fd("\n╔════════════════════════════════════╗\n", 2);
	ft_putstr_fd("║         FRACT'OL - USE             ║\n", 2);
	ft_putstr_fd("╠════════════════════════════════════╣\n", 2);
	ft_putstr_fd("║ ./fractol mandelbrot               ║\n", 2);
	ft_putstr_fd("║ ./fractol julia <real> <imag>      ║\n", 2);
	ft_putstr_fd("╠════════════════════════════════════╣\n", 2);
	ft_putstr_fd("║ Exemples Julia:                    ║\n", 2);
	ft_putstr_fd("║   ./fractol julia -0.7 0.27015     ║\n", 2);
	ft_putstr_fd("║   ./fractol julia -0.4 0.6         ║\n", 2);
	ft_putstr_fd("║   ./fractol julia 0.285 0.01       ║\n", 2);
	ft_putstr_fd("╚════════════════════════════════════╝\n\n", 2);
}
