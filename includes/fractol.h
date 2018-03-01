/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:51:21 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/01 17:12:22 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** INCLUDES
*/

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

/*
** MACROS
*/

# define WIN_LENGTH 1600
# define WIN_HEIGHT 1200

/*
** ENUMERATIONS
*/

typedef enum	e_fractal_type
{
	JULIA,
	MANDELBROT
}				t_fractal_type;

/*
** STRUCTURES
*/

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_color;

typedef struct	s_point
{
	unsigned int	x;
	unsigned int	y;
}				t_point;

typedef struct	s_fractal
{
	t_fractal_type	type;

}

typedef struct	s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_height;
	int				win_length;
	void			*img_ptr;
	void			*img_str;
	int				line_size;
	int				img_height;
	int				img_length;
	double			zoom;
	t_point			center_point;
}				t_env;

/*
** PROTOTYPES
*/

#endif
