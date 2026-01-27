/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <osousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:25:45 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/27 11:26:34 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int fractal_iter(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	temp_real;

	iter = 0;
	while ((z.real * z.real + z.imag * z.imag) <= 4.0 && iter < max_iter)
	{
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp_real;
		iter++;
	}
	return iter;
}
