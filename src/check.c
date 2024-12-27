/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:14:11 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 00:56:42 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_width(char *line)
{
	static int	max_width = 0;
	int			width;

	width = 0;
	width = ft_count_words_space(line);
	if (max_width == 0)
		max_width = width;
	else if (max_width != width)
	{
		error();
		return (0);
	}
	return (max_width);
}

int	check_filetype(char *av[])
{
	char	*filetype;
	char	*input;
	int		len;
	int		i;

	i = 0;
	filetype = ".fdf";
	len = ft_strlen(av[1]);
	while (i < 4)
	{
		if (!(filetype[3 - i] == av[1][len - i - 1]))
			return (0);
		i++;
	}
	return (1);
}

void	check_exceed(t_env *env, int x, int y, char **px)
{
	if (env->pt[y][x].z > 100000 || env->pt[y][x].z < -100000)
	{
		env->map_incorrect = 1;
		env->pt[y][x].z = 0;
	}
}
