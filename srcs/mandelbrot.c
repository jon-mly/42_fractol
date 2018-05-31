/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:33:31 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/05/31 16:08:14 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					init_mandelbrot(t_env *env)
{
	double		proportion;

	env->fractal.type = MANDELBROT;
	env->fractal.max_iteration = 50;
	env->fractal.min_x = -2.1;
	env->fractal.max_x = 0.6;
	proportion = (env->fractal.max_x - env->fractal.min_x) / WIN_LENGTH;
	env->fractal.min_y = -(proportion * WIN_HEIGHT) / 2;
	env->fractal.max_y = (proportion * WIN_HEIGHT) / 2;
	env->zoom = (double)(env->win_length) / (double)(env->fractal.max_x -
				env->fractal.min_x);
}

/*
** Returns the number of iterations that have been done before reaching a limit
** for the suite. The value returned is slightly adjusted to also consider the
** last complex value iterated (if over 4). It allows to draw a smoother
** gradient.
*/

static double				iterate(double x, double y, t_env *env)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	double		i;

	c.r = x / env->zoom + env->fractal.min_x;
	c.i = y / env->zoom + env->fractal.min_y;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (++i <= env->fractal.max_iteration)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		if (z.r * z.r + z.i * z.i > 4)
			return (i + 1 - log(log(sqrt(z.r * z.r + z.i * z.i))) / log(2));
	}
	return (i);
}

static void				*draw_lines(void *arg)
{
	t_thread_data	data;
	int				x;
	int				y;
	double			iterations;

	data = *((t_thread_data*)arg);
	y = data.y_min - 1;
	while (++y < data.y_max)
	{
		x = -1;
		while (++x < data.env->win_length)
		{
			iterations = iterate((double)(x), (double)(y), data.env);
			if (iterations > data.env->fractal.max_iteration)
				fill_pixel(data.env, x, y, BLACK);
			else
				fill_pixel(data.env, x, y, mixed_color(iterations /
					(double)data.env->fractal.max_iteration));
		}
	}
	ft_memdel(&arg);
	pthread_exit(NULL);
	return (NULL);
}

static t_thread_data	*thread_data(t_env *env, int thread_rank,
		int total_threads)
{
	t_thread_data	*data;

	if (!(data = (t_thread_data*)malloc(sizeof(t_thread_data))))
		exit_error(env);
	data->env = env;
	data->y_min = thread_rank * env->img_height / total_threads;
	data->y_max = (thread_rank + 1) * env->img_height / total_threads;
	return (data);
}

void					redraw_mandelbrot(t_env *env)
{
	pthread_t	thread_0;
	pthread_t	thread_1;
	pthread_t	thread_2;
	pthread_t	thread_3;

	if (pthread_create(&thread_0, NULL, draw_lines,
				(void*)(thread_data(env, 0, 4))))
		exit_error(env);
	if (pthread_create(&thread_1, NULL, draw_lines,
				(void*)(thread_data(env, 1, 4))))
		exit_error(env);
	if (pthread_create(&thread_2, NULL, draw_lines,
				(void*)(thread_data(env, 2, 4))))
		exit_error(env);
	if (pthread_create(&thread_3, NULL, draw_lines,
				(void*)(thread_data(env, 3, 4))))
		exit_error(env);
	pthread_join(thread_0, NULL);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
}
