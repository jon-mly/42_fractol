/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:33:31 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/10 17:42:08 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					init_mandelbrot(t_env *env)
{
	env->fractal.type = MANDELBROT;
	env->fractal.max_iteration = 50;
	env->fractal.min_x = -2.1;
	env->fractal.max_x = 0.6;
	env->fractal.min_y = -1.2;
	env->fractal.max_y = 1.2;
	env->zoom = (double)(env->win_length / (env->fractal.max_x -
				env->fractal.min_x));
}

static int				iterate(double x, double y, t_env *env)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;

	c.r = x / env->zoom + env->fractal.min_x;
	c.i = y / env->zoom + env->fractal.min_y;
	c.r = 0;
	c.i = 0;
	i = 0;
	while (++i <= env->fractal.max_iteration)
	{
		tmp = z.r;
		z.r = z.r * z.r + z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		if (z.r * z.r + z.i * z.i > 4)
			return (i);
	}
	return (i);
}

static unsigned int		blue(int iterations, t_env *env)
{
	double		blue;

	blue = ((double)(iterations) / (double)(env->fractal.max_iteration)
		* (double)(env->fractal.max_iteration));
	return ((unsigned int)blue);
}

void				redraw_mandelbrot(t_env *env)
{
	int				x;
	int				y;
	int				iterations;

	y = -1;
	while (++y < env->win_height)
	{
		x = -1;
		while (++x < env->win_length)
		{
			iterations = iterate((double)(x) / env->zoom + env->fractal.min_x,
					(double)(y) / env->zoom + env->fractal.min_y, env);
			if (iterations > env->fractal.max_iteration)
				fill_pixel(env, x, y, color_from(255, 0, 0));
			else
			{
				fill_pixel(env, x, y, color_from(0, 0, blue(iterations, env)));
			}
		}
	}
}
