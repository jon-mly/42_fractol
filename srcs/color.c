/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:51:30 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/05/31 16:22:48 by jmlynarc         ###   ########.fr       */
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

static t_color	mix_colors(t_color color1, t_color color2, double proportion)
{
	t_color		color;

	color.r = color1.r + (int)((double)(color2.r - color1.r) * proportion);
	color.g = color1.g + (int)((double)(color2.g - color1.g) * proportion);
	color.b = color1.b + (int)((double)(color2.b - color1.b) * proportion);
	return (color);
}

t_color		mixed_color(double proportion)
{
	if (proportion < 0.25)
		return (mix_colors(RED, ORANGE, proportion * 4));
	else if (proportion < 0.5)
		return (mix_colors(ORANGE, WHITE, (proportion - 0.25) * 4));
	else if (proportion < 0.75)
		return (mix_colors(WHITE, BLUE, (proportion - 0.5) * 4));
	else
		return (mix_colors(BLUE, BLACK, (proportion - 0.75) * 4));
}

int			endian_color(unsigned int r, unsigned g, unsigned int b)
{
	int			endian_color;

	endian_color = 0;
	endian_color = ((b & 0xFF) << 16) + ((g & 0xFF) << 8) + (r & 0xFF);
	return (endian_color);
}
