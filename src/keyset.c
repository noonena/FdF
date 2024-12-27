/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:59:14 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 18:02:04 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_shift(t_env *env, keys_t key)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (x < env->map_width)
		{
			if (key == MLX_KEY_UP)
				env->pt[y][x].z += 1;
			if (key == MLX_KEY_DOWN)
				env->pt[y][x].z -= 1;
			if (key == MLX_KEY_LEFT)
				env->pt[y][x].x -= 1;
			if (key == MLX_KEY_RIGHT)
				env->pt[y][x].x += 1;
			x++;
		}
		y++;
	}
}

static void	ft_rotate(t_env *env, keys_t key)
{
	if (key == MLX_KEY_W)
		env->x_degree += 1;
	if (key == MLX_KEY_S)
		env->x_degree -= 1;
	if (key == MLX_KEY_A)
		env->z_degree += 1;
	if (key == MLX_KEY_D)
		env->z_degree -= 1;
}

static void	reset_window(t_env *env)
{
	mlx_delete_texture(env->texture);
	free_map(env->pt, env);
	mlx_terminate(env->mlx);
	free(env);
	exit (0);
}

void	onkeypress(mlx_key_data_t key_data, void *environment)
{
	t_env	*env;

	env = (t_env *) environment;
	if (key_data.key == MLX_KEY_Z && env->zoom < 100)
		env->zoom += 0.2;
	if (key_data.key == MLX_KEY_X && env->zoom > 1.4)
		env->zoom -= 0.2;
	ft_rotate(env, key_data.key);
	ft_shift(env, key_data.key);
	if (key_data.key == MLX_KEY_R)
		reset_image(env);
	if (key_data.key == MLX_KEY_I)
		set_to_isometric(env);
	if (key_data.key == MLX_KEY_O)
		set_randomly(env);
	if (key_data.key == MLX_KEY_ESCAPE)
		reset_window(env);
}
