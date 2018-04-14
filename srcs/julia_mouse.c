#include "fractol.h"

void	change_julia_coord(int x, int y, t_env *env)
{
	double		julia_x;
	double		julia_y;

	julia_x = (double)(x - env->img_length / 2) / (double)1000;
	julia_y = (double)(y - env->img_height / 2) / (double)1000;
	env->fractal.julia_x = julia_x;
	env->fractal.julia_y = julia_y;
}

