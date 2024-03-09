/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:12 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/09 16:07:37 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	basic_validation(int argc, char *argv[])
{
	size_t	len;
	int		fd;

	if (argc != 2)
		return (error_message("Usage: ./cub3d <file_path.cub>"));
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1][len - 4], ".cub", 4))
		return (error_message("The map must be a valid .cub file"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno)));
	return (1);
}
