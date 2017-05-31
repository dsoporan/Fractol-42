/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:39:25 by dsoporan          #+#    #+#             */
/*   Updated: 2017/05/31 16:23:05 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = ((double)x - env->sx / 2) / env->zoom + env->move[0];
	env->pt[1] = ((double)y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0x20DB00;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp - z[1] * z[1] + env->pt[0];
		z[1] = 2 * tmp * z[1] + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x20DB00;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	burning(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = ((double)x - env->sx / 2) / env->zoom + env->move[0];
	env->pt[1] = ((double)y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0x20DB00;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env->pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x20DB00;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	julia(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = ((double)x - env->sx / 2) / env->zoom + env->move[0];
	z[1] = ((double)y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0x20DB00;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp - z[1] * z[1] + env->pt[0];
		z[1] = 2 * tmp * z[1] + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x20DB00;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	julol(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = ((double)x - env->sx / 2) / env->zoom + env->move[0];
	z[1] = ((double)y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0xDB0000;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = absol(z[0]);
		z[0] = tmp * tmp - absol(z[1]) * absol(z[1]) + env->pt[0];
		z[1] = 2 * tmp * absol(z[1]) + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x20DB00;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}

void	mandeldeux(int x, int y, t_env *env)
{
	int		i;
	double	tmp;
	double	z[2];
	int		col;

	z[0] = 0;
	z[1] = 0;
	env->pt[0] = ((double)x - env->sx / 2) / env->zoom + env->move[0];
	env->pt[1] = ((double)y - env->sy / 2) / env->zoom + env->move[1];
	i = 0;
	col = 0x20DB00;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->i_max)
	{
		tmp = z[0];
		z[0] = tmp * tmp * tmp - 3 * tmp * z[1] * z[1] + env->pt[0];
		z[1] = 3 * tmp * tmp * z[1] - z[1] * z[1] * z[1] + env->pt[1];
		col -= env->colmod;
		if (col < 0)
			col = 0x20DB00;
		i++;
	}
	pixel(x, y, (i == env->i_max ? 0 : col), env);
}
