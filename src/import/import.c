/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/09 16:57:52 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	import(int argc, char *argv[], t_level *lvl)
{
	int	fd;

	fd = basic_validation(argc, argv);
	if (fd <= 0)
		return (0);
	get_elements(fd, lvl);
	close(fd);
	return (1);
}
