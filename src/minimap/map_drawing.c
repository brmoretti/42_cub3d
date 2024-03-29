/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:06:13 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/18 19:12:40 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_map(t_cub *cub)
{
	int		i;
	int		j;
	int		pos[2];
	char	c;

	i = -1;
	while (cub->level.map[++i][0])
	{
		j = -1;
		while (cub->level.map[i][++j])
		{
			c = cub->level.map[i][j];
			pos[0] = j * (cub->mini.border + cub->mini.side) + MINI_X;
			pos[1] = i * (cub->mini.border + cub->mini.side) + MINI_Y;
			if (c == '1' && mlx_image_to_window(cub->mlx,
					cub->mini.wall, pos[0], pos[1]) < 0)
				exit (42);
			else if (ft_strchr("0NSEW", c)
				&& mlx_image_to_window(cub->mlx,
					cub->mini.floor, pos[0], pos[1]) < 0)
				exit (42);
			if (ft_strchr("NSEW", c)
				&& mlx_image_to_window(cub->mlx, cub->mini.player,
					pos[0] + 3 * cub->mini.side / 8,
					pos[1] + 3 * cub->mini.side / 8) < 0)
				exit (42);
		}
	}
}
