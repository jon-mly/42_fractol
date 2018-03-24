/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:51:21 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/16 16:09:04 by jmlynarc         ###   ########.fr       */
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
# include <pthread.h>

/*
** MACROS
*/

# define WIN_LENGTH 1200
# define WIN_HEIGHT 1200

/*
** ENUMERATIONS
*/

typedef enum	e_fractal_type
{
	JULIA,
	MANDELBROT,
	BURNINGSHIP
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

typedef struct	s_complex
{
	double			r;
	double			i;
}				t_complex;

typedef struct	s_fractal
{
	t_fractal_type	type;
	double			julia_x;
	double			julia_y;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	int				max_iteration;
}				t_fractal;

typedef struct	s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_height;
	int				win_length;
	void			*img_ptr;
	unsigned char	*img_str;
	int				line_size;
	int				img_height;
	int				img_length;
	double			zoom;
	t_point			center_point;
	t_fractal		fractal;
}				t_env;

typedef struct	s_thread_data
{
	int				y_min;
	int				y_max;
	t_env			*env;
}				t_thread_data;

/*
** PROTOTYPES
*/

t_color		color_from(unsigned char r, unsigned char g, unsigned char b);
void		fill_pixel(t_env *env, int x, int y, t_color color);
void		exit_error(t_env *env);
void		exit_normally(t_env *env);
void				redraw_mandelbrot(t_env *env);
void					init_mandelbrot(t_env *env);
void		redraw_image(t_env *env);
t_color		mixed_color(double proportion);
void		move_frame_left(t_env *env);
void		move_frame_right(t_env *env);
void		move_frame_up(t_env *env);
void		move_frame_down(t_env *env);
void		handle_key(int key, t_env *env);
void		zoom_up(t_env *env);
void		zoom_down(t_env *env);
void		init_julia(t_env *env, double x, double y);
void				redraw_julia(t_env *env);
void					init_burningship(t_env *env);
void				redraw_burningship(t_env *env);

#endif
