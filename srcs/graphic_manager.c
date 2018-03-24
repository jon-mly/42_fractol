/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:25:05 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/16 16:09:51 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		redraw_image(t_env *env)
{
	int			bpp;
	int			s_l;
	int			endian;

	if (env->img_ptr)
		mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	if (!(env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_length, env->win_height)))
		return;
	env->img_length = env->win_length;
	env->img_height = env->win_height;
	env->img_str = (unsigned char *)(mlx_get_data_addr(env->img_ptr, &bpp, &s_l, &endian));
	env->line_size = s_l / 4;
	if (env->fractal.type == MANDELBROT)
		redraw_mandelbrot(env);
	else if (env->fractal.type == JULIA)
		redraw_julia(env);
	else if (env->fractal.type == BURNINGSHIP)
		redraw_burningship(env);
	mlx_put_image_to_window((void *)env, env->win_ptr, env->img_ptr, 0, 0);
}
