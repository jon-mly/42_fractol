#include "fractol.h"

int		mouse_event(int event, int x, int y, void *param)
{
	t_env		*env;

	env = (t_env *)param;
	if (event == MOUSE_SCROLL_UP)
		zoom_out(env);
	else if (event == MOUSE_SCROLL_DOWN)
		zoom_in(env);
	else
		return (0);
	redraw_image(env);
	return (0);
}

int		mouse_pointer_event(int x, int y, void *param)
{
	t_env		*env;

	env = (t_env *)param;
	if (x < 0 || x >= env->win_length || y < 0 || y >= env->win_height)
		return (0);
	if (env->fractal.type != JULIA)
		return (0);
	if (!env->fractal.julia_capture_mouse)
		return (0);
	change_julia_coord(x, y, env);
	redraw_image(env);
}
