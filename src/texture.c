/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:46 by euleow            #+#    #+#             */
/*   Updated: 2024/12/05 22:01:42 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_texture(mlx_texture_t *texture, int x, int y, size_t rgb)
{
	size_t	position;

	if (x < 0 || y < 0)
		return (0);
	if (x >= texture->width || y >= texture->height)
		return (0);
	position = (y * texture->width * 4) + (x * 4);
	texture->pixels[position] = rgb >> 16 & 0xFF;
	texture->pixels[position + 1] = rgb >> 8 & 0xFF;
	texture->pixels[position + 2] = rgb & 0xFF;
	texture->pixels[position + 3] = 0xFF;
	return (1);
}

void	fill_background(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->texture->height)
	{
		x = 0;
		while (x < env->texture->width)
		{
			draw_texture(env->texture, x, y, BG_COLOR);
			x++;
		}
		y++;
	}
}

mlx_texture_t	*set_win(size_t w, size_t h, t_env *env)
{
	env->texture = malloc(sizeof(mlx_texture_t));
	env->texture->width = w;
	env->texture->height = h;
	env->texture->bytes_per_pixel = 4;
	env->texture->pixels = malloc(sizeof(uint8_t) * w * h * 4);
	fill_background(env);
	return (env->texture);
}
