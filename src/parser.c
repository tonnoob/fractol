#include "../includes/fractol.h"

static int parse_args(int ac, char **av, t_fractal *f)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		data_init(f, "Mandelbrot");
		return (1);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		data_init(f, "Julia");
		f->julia_v.real = ft_atod(av[2]);
		f->julia_v.imag = ft_atod(av[3]);   
		return (1);
	}
	return (0);
}
