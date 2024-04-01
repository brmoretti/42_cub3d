/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:34:39 by vde-frei          #+#    #+#             */
/*   Updated: 2024/03/31 02:42:02 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_time(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (mlx_get_time() > cub->delay)
		cub->render_on = false;
}
