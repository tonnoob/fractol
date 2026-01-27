/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:03:33 by otton-sousa       #+#    #+#             */
/*   Updated: 2026/01/27 12:06:31 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int get_color(int iter, int max_iter)
{
	int		color;
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x0);
	t = (double)iter / (double)max_iter;
	r = (int)(5 * (1-t) * t * t * t * 255);
	g = (int)(2. * (1-t) * (1-t) * t * t * 255);
	b = (int)(5 * (1-t) * (1-t) * (1-t) * t * 255);
	color = (r << 16) | (g << 8) | b;
	return (color);
}
