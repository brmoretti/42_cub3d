/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:15:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/28 19:53:02 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Fills a rectangle in the given image with the specified color.
 *
 * @param img   The image to fill.
 * @param color The color to fill the rectangle with.
 */
void	rectangle_fill(mlx_image_t *img, uint32_t color)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	while (++i < img->width)
	{
		j = -1;
		while (++j < img->height)
			mlx_put_pixel(img, i, j, color);
	}
}

/**
 * @brief Creates a 32-bit color value using the specified RGBA components.
 *
 * This function takes four integer values representing the red, green,
 * blue, and alpha components of a color and combines them into a single
 * 32-bit color value. The red component is shifted 24 bits to the left,
 * the green component is shifted 16 bits to the left, the blue component
 * is shifted 8 bits to the left, and the alpha component is placed in the
 * least significant 8 bits. The resulting color value is returned.
 *
 * @param r The red component of the color (0-255).
 * @param g The green component of the color (0-255).
 * @param b The blue component of the color (0-255).
 * @param a The alpha component of the color (0-255).
 * @return The 32-bit color value created from the RGBA components.
 */
uint32_t	color_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
