/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:01:30 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/03/16 16:09:28 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*init_environment()
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

int		deal_with_key(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (key == 53)
		exit_normally(env);
	else if (key == 123 || key == 124 || key == 125 || key == 126 || key == 14
			|| key == 12)
		handle_key(key, env);
	return (0);
}

int		main(int ac, char** av)
{
	t_env		*env;

	if (!(env = init_environment()))
		exit_error(env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_LENGTH, WIN_HEIGHT,
			"fractol");
	env->win_length = WIN_LENGTH;
	env->win_height = WIN_HEIGHT;
	init_julia(env, 0.3, 0.5);
	redraw_image(env);
	mlx_key_hook(env->win_ptr, deal_with_key, (void*)env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
