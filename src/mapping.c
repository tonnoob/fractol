/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:25:31 by osousa-d          #+#    #+#             */
/*   Updated: 2026/01/28 12:10:32 by otton-sousa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	normalize(double value, double min, double max)
{
	return ((value - min) / (max - min));
}

double	map(double norm, double out_min, double out_max)
{
	return (out_min + norm * (out_max - out_min));
}
