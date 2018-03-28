#include "fractol.h"

void	change_julia_coord(int x, int y, t_env *env)
{
	double		julia_x;
	double		julia_y;

	julia_x = (double)x / (double)100;
	julia_y = (double)y / (double)100;
	env->fractal.julia_x = julia_x;
	env->fractal.julia_y = julia_y;
}

