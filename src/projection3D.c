/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:24 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 00:49:27 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotation_z(t_env *env, t_point *pt)
{
	float		temp_x;
	float		temp_y;
	float		rad;

	rad = env->z_degree * PI / 180.0;
	temp_x = (cos(rad) * (pt->x)) - (sin(rad) * (pt->y));
	temp_y = (sin(rad) * (pt->x)) + (cos(rad) * (pt->y));
	pt->axis[X] = temp_x;
	pt->axis[Y] = temp_y;
	pt->axis[Z] = pt->z;
}

static void	rotation_y(t_env *env, t_point *pt)
{
	float		temp_x;
	float		temp_z;
	float		rad;

	rad = env->y_degree * PI / 180.0;
	temp_x = (cos(rad) * (pt->axis[X])) + (sin(rad) * (pt->axis[Z]));
	temp_z = (-sin(rad) * (pt->axis[X])) + (cos(rad) * (pt->axis[Z]));
	pt->axis[X] = temp_x;
	pt->axis[Z] = temp_z;
}

static void	rotation_x(t_env *env, t_point *pt)
{
	float		temp_y;
	float		temp_z;
	float		rad;

	rad = env->x_degree;
	temp_y = (cos(rad) * (pt->axis[Y])) - (sin(rad) * (pt->axis[Z]));
	temp_z = (sin(rad) * (pt->axis[Y])) + (cos(rad) * (pt->axis[Z]));
	pt->axis[Y] = temp_y;
	pt->axis[Z] = temp_z;
}

t_point	*adjust(t_env *env, t_point *pt)
{
	if (!pt)
		error();
	if (!pt->adj)
	{
		pt->x = pt->x - (env->map_width / 2);
		pt->y = pt->y - (env->map_height / 2);
		pt->adj = 1;
	}
	rotation_z(env, pt);
	rotation_x(env, pt);
	rotation_y(env, pt);
	pt->axis[X] = pt->axis[X] * env->zoom + WIDTH / 2;
	pt->axis[Y] = pt->axis[Y] * env->zoom + HEIGHT / 2;
	return (pt);
}

void	projected2d(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (x < env->map_width)
		{
			if (x < env->map_width - 1)
				draw_line(adjust(env, &(env->pt[y][x])), \
				adjust(env, &(env->pt[y][x + 1])), env->texture);
			if (y < env->map_height - 1)
				draw_line(adjust(env, &(env->pt[y][x])), \
				adjust(env, &(env->pt[y + 1][x])), env->texture);
			x++;
		}
		y++;
	}
}
