/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:52 by brmoretti         #+#    #+#             */
/*   Updated: 2024/04/01 11:55:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"
# include "MLX42.h"

//CONSTANTS
# define M_PI 3.14159265358979323846

//.CUB FILES DEFINITIONS
# define MAX_ROWS 100
# define MAX_COLS 80

//RAYCASTING
# define N_RAYS 400

//MLX WINDOW PROPERTIES
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

//MOVEMENTS
# define ANGULAR_SPEED 0.09
# define LINEAR_SPEED 0.09

# define FOV 0.66
# define BOX_HEIGHT 150.0

//TEXTURES
# define DOOR_TEX "./textures/wolfenstein3D/miscelaneous/door.png"
# define KNIFE_TEX "./textures/wolfenstein3D/miscelaneous/knifewalk.png"
# define KNIFE_H_TEX "./textures/wolfenstein3D/miscelaneous/knifehit.png"

typedef struct s_weapon
{
	mlx_image_t	*walk;
	mlx_image_t	*attack;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
}	t_weapon;

typedef struct s_level
{
	char	no[MAX_COLS + 1];
	char	so[MAX_COLS + 1];
	char	ea[MAX_COLS + 1];
	char	we[MAX_COLS + 1];
	int		f[3];
	int		c[3];
	char	map[MAX_ROWS + 1][MAX_COLS + 1];
	size_t	x_size;
	size_t	y_size;
}	t_level;

typedef struct s_minimap
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	int			side;
	int			border;
}	t_minimap;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_plane
{
	double	x;
	double	y;
}	t_plane;

typedef struct s_render
{
	int				width;
	mlx_image_t		*floor;
	mlx_image_t		*ceiling;
	mlx_image_t		*boxes[N_RAYS];
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	mlx_texture_t	*door;
	mlx_texture_t	*knife1;
	mlx_texture_t	*knife2;
}	t_render;

typedef struct s_ray
{
	int		index;
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	perp_wall_dist;
	int		tex_x;
	int		side;
	char	obj;
}	t_ray;

typedef struct s_cub
{
	mlx_t		*mlx;
	t_level		level;
	t_minimap	mini;
	t_weapon	weapon;
	t_player	player;
	t_plane		plane;
	t_render	*render;
	double		door_last_time;
	double		delay;
	bool		render_on;
}	t_cub;

enum	e_direction
{
	CLOCKWISE = 1,
	COUNTERCLOCKWISE = -1
};

enum	e_side
{
	NORTH = 2,
	SOUTH = -2,
	EAST = 1,
	WEST = -1
};

void		import(int argc, char *argv[], t_level *lvl);
void		minimap_square_size_and_border(t_cub *cub);
void		minimap(t_cub *cub);
t_ray		*raycasting(t_cub *cub, int ray_index);
void		render_init(t_cub *cub);
void		render_destroy(t_cub *cub);
void		render(t_cub *cub);
void		set_player_dir(t_cub *cub, int i, int j);
int			error_message(const char *error_msg);

//HOOK_FUNCTIONS
void		ft_key_hook(mlx_key_data_t keydata, void *param);

//UTILS
uint32_t	color_rgba(int r, int g, int b, int a);
void		rectangle_fill(mlx_image_t *img, uint32_t color);
void		rotate(double *x, double *y, double rad);
void		texture_fill(mlx_image_t *img, mlx_texture_t *tex, int start);
void		knife(t_cub *cub);
void		ft_time(void *param);

#endif
