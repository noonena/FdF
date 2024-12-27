/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:51:31 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 00:10:51 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keep_axis(int fd, t_env *env)
{
	char	*line;
	int		y;

	y = 0;
	env->pt = malloc(sizeof(t_point *) * env->map_height);
	if (!env->pt)
	{
		free_map(env->pt, env);
		error();
	}
	while (y < env->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!process_row(env, y, line))
			break ;
		y++;
		free(line);
	}
}

int	process_row(t_env *env, int y, char *line)
{
	char	**x_width;

	x_width = ft_split_space(line);
	if (!x_width || !*x_width)
	{
		free_split(x_width);
		return (0);
	}
	env->pt[y] = malloc(sizeof(t_point) * env->map_width);
	if (!env->pt[y])
	{
		free_split(x_width);
		return (0);
	}
	set_eachpoint(env, y, x_width);
	free_split(x_width);
	return (1);
}

void	set_eachpoint(t_env *env, int y, char **x_width)
{
	char	**point_x;
	int		x;

	x = 0;
	while (x_width[x])
	{
		env->pt[y][x].x = x;
		env->pt[y][x].y = y;
		env->pt[y][x].adj = 0;
		point_x = ft_split(x_width[x], ',');
		if (point_x)
		{
			env->pt[y][x].z = ft_atoi_base(point_x[0], 10);
			check_exceed(env, x, y, point_x);
			if (point_x[1])
				env->pt[y][x].color = ft_atoi_base((point_x[1]), 16);
			else
				env->pt[y][x].color = LINE_COLOR;
			free_split(point_x);
		}
		x++;
	}
}

int	getline_setwh(int fd, t_env *env)
{
	char	*line;
	int		height;
	int		width;

	height = 0;
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		width = check_width(line);
		height++;
		free(line);
	}
	env->map_height = height;
	env->map_width = width;
	close(fd);
	return (1);
}
