/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:55:59 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/06/17 13:26:19 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_pixel(t_env *env, int x, int y, t_color color)
{
	int			i;

	if (!((x < 0 || x >= env->img_length) ||
			(y < 0 || y >= env->img_height)))
	{
		i = (y * env->line_size) * 4 + x * 4;
		env->img_str[i] = color.r;
		env->img_str[i + 1] = color.g;
		env->img_str[i + 2] = color.b;
		env->img_str[i + 3] = 0;
	}
}
