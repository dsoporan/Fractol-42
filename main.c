/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:39:19 by dsoporan          #+#    #+#             */
/*   Updated: 2017/05/31 16:10:18 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void caller2(t_env *env, char *arg)
{
	if (ft_strcmp(arg, "Extra3") == 0)
		env->fract = 5;
	if (ft_strcmp(arg, "Extra4") == 0)
		env->fract = 6;
	if (ft_strcmp(arg, "Extra5") == 0)
		env->fract = 7;
}

static void	caller(t_env *env, char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0 ||
		ft_strcmp(arg, "Burningship") == 0)
	{
		env->x1 = -2.1;
		env->y1 = -1.2;
	}
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		env->fract = 0;
	if (ft_strcmp(arg, "Burningship") == 0)
		env->fract = 2;
	if (ft_strcmp(arg, "Julia") == 0)
		env->fract = 1;
	if (ft_strcmp(arg, "Julol") == 0)
		env->fract = 3;
	if (ft_strcmp(arg, "Mandeldeux") == 0)
		env->fract = 4;
	caller2(env, arg); 
	mlx_hook(env->win, 6, 0, motion_funct, env);
	mlx_hook(env->win, 4, 0, zoom_funct, env);
	mlx_hook(env->win, 2, 0, key_funct, env);
	mlx_hook(env->win, 17, 0, quit_funct, env);
	fractals(env);
	mlx_loop(env->mlx);
}

static void	init_val(t_env *env, char *arg)
{
	int		bpp;
	int		edan;

	env->colmod = 135000;
	env->zoom = env->sx / 3;
	env->pt[0] = 0.285;
	env->pt[1] = 0.01;
	env->i_max = 50;
	env->pos_x = 0;
	env->pos_y = 0;
	env->is_move = 1;
	env->is_indent = 1;
	env->is_text = 1;
	env->move[0] = env->x1;
	env->move[1] = env->y1;
	env->meml = mlx_get_data_addr(env->img, &bpp, &(env->sizel), &edan);
	caller(env, arg);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->sx = 800;
	env->sy = 800;
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
		ft_strcmp(argv[1], "Julia") != 0 &&
		ft_strcmp(argv[1], "Julol") != 0 &&
		ft_strcmp(argv[1], "Mandeldeux") != 0 &&
		ft_strcmp(argv[1], "Burningship") != 0 &&
		ft_strcmp(argv[1], "Extra3") != 0 &&
		ft_strcmp(argv[1], "Extra4") != 0 &&
		ft_strcmp(argv[1], "Extra5") != 0) ||
		!(env->mlx = mlx_init()) ||
		!(env->win = mlx_new_window(env->mlx, env->sx, env->sy, "Fract'ol")) ||
		!(env->img = mlx_new_image(env->mlx, env->sx, env->sy)))
	{
		ft_putendl("Parameters :\n");
		ft_putendl("Necessary: Mandelbrot , Julia , Burningship;");
		ft_putendl("Optional: Mandeldeux , Julol , Extra3 , Extra4 , Extra5;");
	}
	else
		init_val(env, argv[1]);
	return (0);
}
