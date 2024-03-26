/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:29:07 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/26 18:40:36 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "MLX42.h"
#include "cub3d.h"
#include "import.h"
#include <math.h>
#include <stdio.h>

void	mock_define_color(uint32_t *color, t_ray *ray, t_cub *cub)
{
	// load textures
	cub->render->tex[NO] = mlx_load_png("redbriks.png");
	cub->render->tex[SO] = mlx_load_png("redbriks.png");
	cub->render->tex[WE] = mlx_load_png("redbriks.png");
	cub->render->tex[EA] = mlx_load_png("redbriks.png");

	// texture calcs
	int y, x;
	y = cub->level.y_size;
	x = cub->level.x_size;
	int	texture_num = cub->level.map[y][x] - 1;

	// calc wallX
	double	wall_x = ray->perp_wall_dist;
	if (ray->side == EAST || ray->side == WEST)
		wall_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	else
	 wall_x = cub->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	wall_x -= floor((wall_x));

	int	tex_x = int((wall_x) * double(TEX_W)));
	if (ray->side == 0 && ray->dir_y > 0)
		tex_x = TEX_W - tex_x - 1;
	if (ray->side == 1 && ray->dir_x < 0)
		tex_x = TEX_W - tex_x - 1;

//TODO: finish function calculating Y and printing textures



	if (ray->side == -1)
		*color = WHITE;
	else if (ray->side == 1)
		*color = RED;
	else if (ray->side == 2)
		*color = GREEN;
	else
		*color = BLUE;
}

void	destroy_box(t_cub *cub, int index)
{
	mlx_image_t	**img;

	img = &cub->render->boxes[index];
	if (*img)
	{
		mlx_delete_image(cub->mlx, *img);
		*img = NULL;
	}
}

void	render_box(t_cub *cub, t_ray *ray, int box_height)
{
	uint32_t	color;
	mlx_image_t	**img;
	uint32_t	x;
	uint32_t	y;

	mock_define_color(&color, ray, cub);
	img = &cub->render->boxes[ray->index];
	destroy_box(cub, ray->index);
	*img = mlx_new_image(cub->mlx, cub->render->width, box_height);
	rectangle_fill(*img, color);
	x = ray->index * cub->render->width;
	y = WINDOW_HEIGHT / 2 - box_height / 2;
	mlx_image_to_window(cub->mlx, *img, x, y);
}

void	render(t_cub *cub)
{
	int		i;
	t_ray	*ray;
	int		height;

	i = -1;
	while (++i < N_RAYS)
	{
		ray = raycasting(cub, i);
		if (!ray)
			exit (EXIT_FAILURE); //panic
		height = (int)(BOX_HEIGHT / ray->perp_wall_dist);
		if (height > WINDOW_HEIGHT)
			height = WINDOW_HEIGHT;
		render_box(cub, ray, height);
		free (ray);
	}
}
