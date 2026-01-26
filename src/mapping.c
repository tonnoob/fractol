#include "../includes/fractol.h"

double	map(double value, double in_min, double in_max, double out_min, double out_max)
{
	double	cord_pixel;

	cord_pixel = out_min + (value - in_min) * (out_max - out_min) / (in_max - in_min);
	return (cord_pixel);
}
