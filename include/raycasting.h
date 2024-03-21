/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:27:32 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/21 16:24:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

void	set_initial_player_pos(t_cub *cub);
void	set_initial_plane(t_cub	*cub);
void	rotate(double *x, double *y, double rad);
void	raycast_loop(t_cub *cub);

#endif
