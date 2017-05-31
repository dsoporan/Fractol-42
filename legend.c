/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:39:11 by dsoporan          #+#    #+#             */
/*   Updated: 2017/05/31 16:18:53 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	text(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 11, 1, 0, "Quit : Esc");
	mlx_string_put(env->mlx, env->win, 10, 0, 0xDDDDDD, "Quit : Esc");
	mlx_string_put(env->mlx, env->win, 11, 21, 0, "Move : arrows");
	mlx_string_put(env->mlx, env->win, 10, 20, 0xDDDDDD, "Move : arrows");
	mlx_string_put(env->mlx, env->win, 11, 41, 0, "Zoom : mouse or / *");
	mlx_string_put(env->mlx, env->win, 10, 40, 0xDDDDDD, "Zoom : mouse or / *");
}

void	special_text(t_env *env)
{
	mlx_string_put(env->mlx, env->win, env->sx - 184, 1, 0, "Move end:");
	mlx_string_put(env->mlx, env->win, env->sx - 185, 0, 0xDDDDDD, "Move end:");
	if (env->is_move == 1)
	{
		mlx_string_put(env->mlx, env->win, env->sx - 32, 1, 0x55BB55, "ON");
		mlx_string_put(env->mlx, env->win, env->sx - 33, 0, 0x00FF00, "ON");
	}
	else
	{
		mlx_string_put(env->mlx, env->win, env->sx - 32, 1, 0xBB5555, "OFF");
		mlx_string_put(env->mlx, env->win, env->sx - 33, 0, 0xFF0000, "OFF");
	}
	mlx_string_put(env->mlx, env->win, env->sx - 184, 21, 0, "Indent home:");
	mlx_string_put(env->mlx, env->win, env->sx - 185, 20, 0xDDDDDD,
			"Indent home:");
	if (env->is_indent == 0)
	{
		mlx_string_put(env->mlx, env->win, env->sx - 32, 21, 0x55BB55, "ON");
		mlx_string_put(env->mlx, env->win, env->sx - 33, 20, 0x00FF00, "ON");
	}
	else
	{
		mlx_string_put(env->mlx, env->win, env->sx - 32, 21, 0xBB5555, "OFF");
		mlx_string_put(env->mlx, env->win, env->sx - 33, 20, 0xFF0000, "OFF");
	}
}

double	absol(double val)
{
	return ((val < 0 ? val * (-1) : val));
}
