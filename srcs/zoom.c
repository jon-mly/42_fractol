/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:47:41 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/16 15:54:46 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_iterations_count(t_env *env)
{
	double	zoom;
	int		max_iter;

	zoom = env->zoom;
	if (zoom < 400)
		max_iter = 25;
	else if (zoom < 1000)
		max_iter = 40;
	else if (zoom < 2000)
		max_iter = 60;
	else if (zoom < 5000)
		max_iter = 70;
	else if (zoom < 10000)
		max_iter = 100;
	else if (zoom < 100000)
		max_iter = 120;
	else if (zoom < 500000)
		max_iter = 150;
	else if (zoom < 1000000)
		max_iter = 175;
	else
		max_iter = 200;
	env->fractal.max_iteration = max_iter;
}

void		zoom_up(t_env *env)
{
	double	shift;

	shift = (0.1 * (env->fractal.max_x - env->fractal.min_x)) / 2;
	env->fractal.min_x += shift;
	env->fractal.min_y += shift;
	env->fractal.max_x -= shift;
	env->fractal.max_y -= shift;
	env->zoom = (double)(env->win_length) / (double)(env->fractal.max_x -
				env->fractal.min_x);
	// TODO: modify number of iterations
	set_iterations_count(env);
}

void		zoom_down(t_env *env)
{
	double	shift;

	shift = (0.1 * (env->fractal.max_x - env->fractal.min_x)) / 2;
	env->fractal.min_x -= shift;
	env->fractal.min_y -= shift;
	env->fractal.max_x += shift;
	env->fractal.max_y += shift;
	env->zoom = (double)(env->win_length) / (double)(env->fractal.max_x -
				env->fractal.min_x);
	// TODO: modify number of iterations
	set_iterations_count(env);
}
