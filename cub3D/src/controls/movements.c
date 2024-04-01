/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:19:46 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/31 02:47:50 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	valid_new_pos(t_cub *cub, double dir_x, double dir_y)
{
	double	delta[2];
	int		map_pos[2];
	double	new_pos[2];

	delta[0] = LINEAR_SPEED * dir_x;
	delta[1] = LINEAR_SPEED * dir_y;
	map_pos[0] = (int)cub->player.pos_x;
	map_pos[1] = (int)cub->player.pos_y;
	new_pos[0] = cub->player.pos_x + delta[0] + dir_x * 0.30;
	if (cub->level.map[map_pos[1]][(int)new_pos[0]] == '0')
		cub->player.pos_x = cub->player.pos_x + delta[0];
	new_pos[1] = cub->player.pos_y + delta[1] + dir_y * 0.30;
	if (cub->level.map[(int)new_pos[1]][map_pos[0]] == '0')
		cub->player.pos_y = cub->player.pos_y + delta[1];
}

static void	wasd(t_cub *cub, keys_t key)
{
	double	dir_x;
	double	dir_y;

	cub->render_on = true;
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
	render(cub);
}

static void	player_plane_rotation(t_cub *cub, int direction)
{
	double	speed;

	cub->render_on = true;
	speed = (double)direction * ANGULAR_SPEED;
	rotate(&cub->player.dir_x, &cub->player.dir_y, speed);
	rotate(&cub->plane.x, &cub->plane.y, speed);
	render(cub);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(cub->mlx);
		return ;
	}
	if (key.key == MLX_KEY_LEFT && !cub->render_on)
		player_plane_rotation(cub, COUNTERCLOCKWISE);
	else if (key.key == MLX_KEY_RIGHT && !cub->render_on)
		player_plane_rotation(cub, CLOCKWISE);
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_A || key.key == MLX_KEY_S
			|| key.key == MLX_KEY_D) && !cub->render_on)
		wasd(cub, key.key);
}
