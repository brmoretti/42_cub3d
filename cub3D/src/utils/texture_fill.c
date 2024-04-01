/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:29:56 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/28 19:54:14 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Fills an image with a texture starting from a specified pixel in the
 * texture. The image must have at least the same height as the texture,
 * preferably the same, and should not be wider than the texture.
 *
 * @param img The image to fill.
 * @param tex The texture to use for filling.
 * @param start The starting position in the texture.
 */
void	texture_fill(mlx_image_t *img, mlx_texture_t *tex, int start)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	color;
	uint8_t		*pixel;

	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
		{
			pixel = tex->pixels + 4 * (i * tex->width + start + j);
			color = color_rgba(*pixel, *(pixel + 1),
					*(pixel + 2), *(pixel + 3));
			mlx_put_pixel(img, i, j, color);
		}
	}
}
