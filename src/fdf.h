/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:51:16 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 01:18:26 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define PI 3.14159
# define WIDTH 1024
# define HEIGHT 1024
# define BG_COLOR 0x0
# define LINE_COLOR 0xFFFFFF
# define X 0
# define Y 1
# define Z 2

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		adj;
	size_t	color;
	float	axis[3];
}	t_point;

typedef struct s_env
{
	float			x_degree;
	float			y_degree;
	float			z_degree;
	float			zoom;
	int				map_width;
	int				map_height;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_point			**pt;
	float			max_z;
	float			min_z;
	int				map_incorrect;
}	t_env;

mlx_texture_t	*set_win(size_t w, size_t h, t_env *env);
int				draw_texture(mlx_texture_t *texture, int x, int y, size_t rgb);
void			error(void);

void			projected2d(t_env *env);

int				draw_line(t_point *start, t_point *end, mlx_texture_t *texture);

int				ft_ascii_todigit(char c);
int				ft_atoi_base(char *nbr, int base);

void			keep_axis(int fd, t_env *env);

void			read_map(char *argv[], t_env *env);
void			free_map(t_point **point, t_env *env);
void			free_split(char **split);

int				getline_setwh(int fd, t_env *env);

int				check_width(char *line);

void			set_mlx(t_env *env);
t_env			*init_env(void);
int				getline_setwh(int fd, t_env *env);
int				process_row(t_env *env, int y, char *line);
void			set_eachpoint(t_env *env, int y, char **x_width);

void			fill_background(t_env *env);

void			onkeypress(mlx_key_data_t key_data, void *environment);

void			rotate_img(t_env *env);
void			keep_axis(int fd, t_env *env);
int				getline_setwh(int fd, t_env *env);

void			reset_image(t_env *env);
void			set_to_isometric(t_env *env);
void			set_randomly(t_env *env);

int				check_filetype(char *av[]);
void			adjust_scale(t_env *env);
void			check_exceed(t_env *env, int x, int y, char **px);
void			free_map_unsuccess(t_point **point, int n);
#endif
