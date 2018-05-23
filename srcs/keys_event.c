/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:46:14 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/05/23 12:51:12 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# include <stdio.h>

int			handle_key(int key, t_env *env)
{
	if (key == KEY_ARROW_RIGHT)
		move_frame_left(env);
	else if (key == KEY_ARROW_LEFT)
		move_frame_right(env);
	else if (key == KEY_ARROW_DOWN)
		move_frame_up(env);
	else if (key == KEY_ARROW_UP)
		move_frame_down(env);
	else if (key == KEY_ZOOM_IN)
		zoom_in(env);
	else if (key == KEY_ZOOM_OUT)
		zoom_out(env);
	else if (key == KEY_MOUSE_CAPTURE && env->fractal.type == JULIA)
		env->fractal.julia_capture_mouse = !env->fractal.julia_capture_mouse;
	else
		return (0);
	redraw_image(env);
	return (0);
}
