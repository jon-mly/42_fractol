/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:01:30 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/04/17 16:24:52 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env			*init_environment(void)
{
	t_env		*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->img_ptr = NULL;
	env->img_str = NULL;
	return (env);
}

int				deal_with_key(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (key == KEY_ESC)
		exit_normally(env);
	else
		handle_key(key, env);
	return (0);
}

static void		init_fractal(char *key, t_env *env)
{
	if (ft_strequ(key, "mandelbrot"))
		init_mandelbrot(env);
	else if (ft_strequ(key, "julia"))
		init_julia(env, 0, 0);
	else if (ft_strequ(key, "burningship"))
		init_burningship(env);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (ac != 2)
		exit_usage();
	if (!ft_strequ(av[1], "mandelbrot") && !ft_strequ(av[1], "julia")
		&& !ft_strequ(av[1], "burningship"))
		exit_usage();
	if (!(env = init_environment()))
		exit_error(env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_LENGTH, WIN_HEIGHT,
			"fractol");
	env->win_length = WIN_LENGTH;
	env->win_height = WIN_HEIGHT;
	init_fractal(av[1], env);
	redraw_image(env);
	mlx_key_hook(env->win_ptr, deal_with_key, (void*)env);
	mlx_mouse_hook(env->win_ptr, mouse_event, (void*)env);
	mlx_hook(env->win_ptr, MOTION_NOTIFY, POINTER_MOTION_MASK,
			mouse_pointer_event, (void*)env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
