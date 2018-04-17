/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:26:21 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/04/17 16:26:44 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					init_burningship(t_env *env)
{
	env->fractal.type = BURNINGSHIP;
	env->fractal.max_iteration = 50;
	env->fractal.min_x = -2.1;
	env->fractal.max_x = 0.6;
	env->fractal.min_y = -1.2;
	env->fractal.max_y = 1.2;
	env->zoom = (double)(env->win_length) / (double)(env->fractal.max_x -
				env->fractal.min_x);
}

static int				iterate(double x, double y, t_env *env)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;

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
			return (i);
		z.r = fabs(z.r);
		z.i = fabs(z.i);
	}
	return (i);
}

static void				*draw_lines(void *arg)
{
	t_thread_data	data;
	int				x;
	int				y;
	int				iterations;

	data = *((t_thread_data*)arg);
	y = data.y_min - 1;
	while (++y < data.y_max)
	{
		x = -1;
		while (++x < data.env->win_length)
		{
			iterations = iterate((double)(x), (double)(y), data.env);
			if (iterations > data.env->fractal.max_iteration)
				fill_pixel(data.env, x, y, color_from(255, 255, 255));
			else
				fill_pixel(data.env, x, y, mixed_color((double)iterations /
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

void					redraw_burningship(t_env *env)
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
