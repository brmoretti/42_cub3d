/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:19:46 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/23 00:28:36 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	valid_new_pos(t_cub *cub, double dir_x, double dir_y)
{
	double	delta[2];
	double	new_pos[2];

	delta[0] = LINEAR_SPEED * dir_x;
	delta[1] = LINEAR_SPEED * dir_y;
	new_pos[0] = cub->player.pos_x + delta[0] + dir_x * 0.10;
	new_pos[1] = cub->player.pos_y + delta[1] + dir_y * 0.10;
	if (cub->level.map[(int)new_pos[1]][(int)new_pos[0]] == '0')
	{
		cub->player.pos_x = cub->player.pos_x + delta[0];
		cub->player.pos_y = cub->player.pos_y + delta[1];
	} 
}

static void	wasd(t_cub *cub, keys_t key)
{
	double	dir_x;
	double	dir_y;

	dir_x = cub->player.dir_x;
	dir_y = cub->player.dir_y;
	if (key == MLX_KEY_A || key == MLX_KEY_D)
		rotate(&dir_x, &dir_y, M_PI / 2);
	if (key == MLX_KEY_S || key == MLX_KEY_A)
	{
		dir_x *= -1;
		dir_y *= -1;
	}
	valid_new_pos(cub, dir_x, dir_y);
}

static void	player_plane_rotation(t_cub *cub, int direction)
{
	double	speed;

	speed = (double)direction * ANGULAR_SPEED;
	rotate(&cub->player.dir_x, &cub->player.dir_y, speed);
	rotate(&cub->plane.x, &cub->plane.y, speed);
}

void	ft_key_hook(mlx_key_data_t keydata, void* param)
{
	t_cub	*cub;
	keys_t	key;

	cub = (t_cub *)param;
	key = keydata.key;
	if (key == MLX_KEY_LEFT)
		player_plane_rotation(cub, COUNTERCLOCKWISE);
	else if (key == MLX_KEY_RIGHT)
		player_plane_rotation(cub, CLOCKWISE);
	if (key == MLX_KEY_W || key == MLX_KEY_A || key == MLX_KEY_S
		|| key == MLX_KEY_D)
		wasd(cub, key);
	render(cub);
}