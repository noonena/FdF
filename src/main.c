/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:13:23 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 00:35:49 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_env *env)
{
	env->texture = set_win(WIDTH, HEIGHT, env);
	if (!env->texture)
		error();
	env->mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	if (!env->mlx)
		error();
}

void	read_map(char *argv[], t_env *env)
{
	int	fd;
	int	fd1;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error();
	fd1 = open(argv[1], O_RDONLY);
	if (fd < 0)
		error();
	if (getline_setwh(fd, env))
		keep_axis(fd1, env);
	adjust_scale(env);
}

int	main(int ac, char *av[])
{
	t_env	*env;

	if (ac != 2 || !av[1])
		error();
	if (!check_filetype(av))
		error();
	env = init_env();
	read_map(av, env);
	if (env->map_incorrect)
	{
		free_map(env->pt, env);
		free(env);
		error();
	}
	set_mlx(env);
	mlx_delete_texture(env->texture);
	free_map(env->pt, env);
	mlx_terminate(env->mlx);
	free(env);
}
