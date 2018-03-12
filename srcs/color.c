/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:51:30 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/10 17:17:56 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		color_from(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 1;
	return (color);
}

t_color		mixed_color(double proportion)
{
	t_color color;

	proportion += 0.1;
	color.r = 255 - (unsigned int)((proportion > 1) ? 1 : proportion *
		255);
	color.g = 255 - (unsigned int)((proportion > 1) ? 1 :
		proportion * 255);
	color.b = 255 - (unsigned int)((proportion > 1) ? 1 :
		proportion * 255);
	return (color);
}

int			endian_color(unsigned int r, unsigned g, unsigned int b)
{
	int			endian_color;

	endian_color = 0;
	endian_color = ((b & 0xFF) << 16) + ((g & 0xFF) << 8) + (r & 0xFF);
	return (endian_color);
}
