#include "../includes/fractol.h"

int main(int ac, char **av)
{
	t_fractal	f;

	if (!parse_args(ac, av, &f))
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	window_init(&f);
	fractal_init(&f);
	fractal_render(&f);
	mlx_mouse_hook(f.win, mouse_handler, &f);
	mlx_hook(f.win, DESTROY_NOTIFY, 0, close_handler, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}


