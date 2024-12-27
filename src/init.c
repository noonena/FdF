/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:35 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 01:17:06 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->x_degree = atan(sqrt(2));
	env->y_degree = 0;
	env->z_degree = 45;
	env->zoom = 30;
	env->map_width = 0;
	env->map_height = 0;
	env->mlx = NULL;
	env->texture = NULL;
	env->image = NULL;
	env->pt = NULL;
	env->max_z = -2147483648;
	env->min_z = 2147483648;
	env->map_incorrect = 0;
	return (env);
}

void	render(void *param)
{
	t_env	*env;

	env = (t_env *) param;
	fill_background(env);
	projected2d(env);
	if (!env->texture)
		error();
	if (env->image)
		mlx_delete_image(env->mlx, env->image);
	env->image = mlx_texture_to_image(env->mlx, env->texture);
	if (!env->image)
		error();
	if (mlx_image_to_window(env->mlx, env->image, 0, 0) < 0)
		error();
}

void	set_mlx(t_env *env)
{
	env->texture = set_win(WIDTH, HEIGHT, env);
	if (!env->texture)
		error();
	env->mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	if (!env->mlx)
		error();
	mlx_key_hook(env->mlx, onkeypress, (void *) env);
	mlx_loop_hook(env->mlx, &render, (void *) env);
	mlx_loop(env->mlx);
}

void	adjust_scale(t_env *env)
{
	float	wscale;
	float	hscale;
	float	zscale;

	wscale = WIDTH * 0.7 / (env->map_width);
	hscale = HEIGHT * 0.7 / (env->map_height);
	zscale = HEIGHT / (env->max_z + -env->min_z);
	if (zscale < wscale && zscale < hscale)
		env->zoom = wscale;
	else if (wscale < hscale)
		env->zoom = wscale;
	else
		env->zoom = hscale;
}
