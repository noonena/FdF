/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:09 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 20:40:47 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	line_color(t_point *point)
{
	if (point->color)
		return (point->color);
	return (LINE_COLOR);
}

int	draw_line(t_point *start, t_point *end, mlx_texture_t *texture)
{
	int		pixels;
	float	dx;
	float	dy;
	float	x_inc;
	float	y_inc;

	dx = end->axis[X] - start->axis[X];
	dy = end->axis[Y] - start->axis[Y];
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	x_inc = start->axis[X];
	y_inc = start->axis[Y];
	while (pixels > 0)
	{
		draw_texture(texture, x_inc, y_inc, line_color(start));
		x_inc += dx;
		y_inc += dy;
		pixels -= 1;
	}
	return (1);
}
