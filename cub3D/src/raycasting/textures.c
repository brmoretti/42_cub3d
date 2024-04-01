/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:27:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/28 14:07:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_x(t_cub *cub, t_ray *ray)
{
	double	wall_x;
	double	tex_width;

	if (ray->side == EAST)
	{
		wall_x = cub->player.pos_y + ray->perp_wall_dist * ray->dir_y;
		tex_width = (double)cub->render->ea->width;
	}
	else if (ray->side == WEST)
	{
		wall_x = cub->player.pos_y + ray->perp_wall_dist * ray->dir_y;
		tex_width = (double)cub->render->we->width;
	}
	else if (ray->side == NORTH)
	{
		wall_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
		tex_width = (double)cub->render->no->width;
	}
	else
	{
		wall_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
		tex_width = (double)cub->render->so->width;
	}
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (tex_width - 1));
}
