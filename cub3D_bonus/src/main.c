/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/28 18:03:29 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	static t_cub	cub;

	import(argc, argv, &cub.level);
#ifdef DEBUG
	printf("Import success\n");
#endif
	cub.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", true);
	render_init(&cub);
	render(&cub);
	mlx_key_hook(cub.mlx, ft_key_hook, &cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	return (0);
}
