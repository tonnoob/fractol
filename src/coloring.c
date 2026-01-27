/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 07:03:33 by otton-sousa       #+#    #+#             */
/*   Updated: 2026/01/27 12:27:15 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

int get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0xF5F2FF); // fundo claro onírico

	t = (double)iter / (double)max_iter;

	// curva lenta, sensação de sonho
	t = pow(t, 0.6);

	r = (int)(sin(t * 4.0 + 0.0) * 30 + 200);
	g = (int)(sin(t * 4.0 + 2.0) * 30 + 195);
	b = (int)(sin(t * 4.0 + 4.0) * 40 + 215);

	return ((r << 16) | (g << 8) | b);
}
