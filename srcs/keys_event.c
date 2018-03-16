/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:46:14 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/16 11:56:12 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		handle_key(int key, t_env *env)
{
	if (key == 123)
		move_frame_left(env);
	else if (key == 124)
		move_frame_right(env);
	else if (key == 126)
		move_frame_up(env);
	else if (key == 125)
		move_frame_down(env);
	else if (key == 12)
		zoom_up(env);
	else if (key == 14)
		zoom_down(env);
	redraw_image(env);
}
