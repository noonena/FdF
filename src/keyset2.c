/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyset2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:31:09 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 19:50:15 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_image(t_env *env)
{
	env->x_degree = 0;
	env->y_degree = 0;
	env->z_degree = 0;
	adjust_scale(env);
}

void	set_to_isometric(t_env *env)
{
	env->x_degree = atan(sqrt(2));
	env->y_degree = 0;
	env->z_degree = 45;
	adjust_scale(env);
}

void	set_randomly(t_env *env)
{
	env->x_degree = atan(sqrt(2));
	env->y_degree = 15;
	env->z_degree = 35;
	env->zoom = 60;
}
