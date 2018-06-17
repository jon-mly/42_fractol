/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:23:48 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/06/17 13:28:44 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		exit_error(t_env *env)
{
	ft_putendl("An error has occured.");
	if (env->img_ptr)
		mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	if (env->win_ptr && env->mlx_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_memdel((void**)(&env));
	exit(0);
}

void		exit_usage(void)
{
	ft_putendl("Usage : ./fractol [mandelbrot/julia/burningship]");
	exit(0);
}

void		exit_normally(t_env *env)
{
	if (env->img_ptr)
		mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	if (env->win_ptr && env->mlx_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_memdel((void**)(&env));
	exit(0);
}
