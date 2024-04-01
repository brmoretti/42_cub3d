/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:29:07 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/28 19:49:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "import.h"
#include <stdlib.h>

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
	mlx_image_t		**img;
	uint32_t		x;
	uint32_t		y;
	mlx_texture_t	*tex;

	img = &cub->render->boxes[ray->index];
	destroy_box(cub, ray->index);
	if (ray->side == NORTH)
		tex = cub->render->no;
	else if (ray->side == SOUTH)
		tex = cub->render->so;
	else if (ray->side == EAST)
		tex = cub->render->ea;
	else
		tex = cub->render->we;
	*img = mlx_new_image(cub->mlx, cub->render->width, tex->height);
	texture_fill(*img, tex, ray->tex_x);
	mlx_resize_image(*img, cub->render->width, box_height * 4);
	x = ray->index * cub->render->width;
	y = WINDOW_HEIGHT / 2 - box_height;
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
		{
			render_destroy(cub);
			mlx_close_window(cub->mlx);
			error_message("Failed allocating ray");
			exit (EXIT_FAILURE);
		}
		height = (int)(BOX_HEIGHT / ray->perp_wall_dist);
		if (height > WINDOW_HEIGHT)
			height = WINDOW_HEIGHT;
		render_box(cub, ray, height);
		free (ray);
	}
}

void	set_player_dir(t_cub *cub, int i, int j)
{
	if (cub->level.map[i][j] == 'E')
		cub->player.dir_x = 1;
	else if (cub->level.map[i][j] == 'N')
		cub->player.dir_y = -1;
	else if (cub->level.map[i][j] == 'W')
		cub->player.dir_x = -1;
	else if (cub->level.map[i][j] == 'S')
		cub->player.dir_y = 1;
}
