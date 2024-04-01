/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:26:21 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/28 19:54:58 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Rotates the given coordinates of a vector (x, y) by the specified angle in
 * radians.
 *
 * @param x - Pointer to the x-coordinate.
 * @param y - Pointer to the y-coordinate.
 * @param rad - The angle in radians.
 */
void	rotate(double *x, double *y, double rad)
{
	double	x_temp;
	double	y_temp;

	x_temp = *x;
	y_temp = *y;
	*x = x_temp * cos(rad) + y_temp * -sin(rad);
	*y = x_temp * sin(rad) + y_temp * cos(rad);
}
