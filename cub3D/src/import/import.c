/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/28 18:37:14 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

void	import(int argc, char *argv[], t_level *lvl)
{
	t_import_elements	lvl_el;

	lvl_el.fd = basic_validation(argc, argv);
	lvl_el.lvl = lvl;
	lvl_el.line = NULL;
	get_elements(&lvl_el);
	get_map(&lvl_el);
	map_validation(lvl);
	close(lvl_el.fd);
}
