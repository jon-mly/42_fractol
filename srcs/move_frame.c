/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:30:36 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/16 11:37:03 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move_frame_left(t_env *env)
{
	double		shift;

	shift = 0.1 * (env->fractal.max_x - env->fractal.min_x);
	env->fractal.min_x -= shift;
	env->fractal.max_x -= shift;
}

void		move_frame_right(t_env *env)
{
	double		shift;

	shift = 0.1 * (env->fractal.max_x - env->fractal.min_x);
	env->fractal.min_x += shift;
	env->fractal.max_x += shift;
}

void		move_frame_up(t_env *env)
{
	double		shift;

	shift = 0.1 * (env->fractal.max_x - env->fractal.min_x);
	env->fractal.min_y += shift;
	env->fractal.max_y += shift;
}

void		move_frame_down(t_env *env)
{
	double		shift;

	shift = 0.1 * (env->fractal.max_x - env->fractal.min_x);
	env->fractal.min_y -= shift;
	env->fractal.max_y -= shift;
}
