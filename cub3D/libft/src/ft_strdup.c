/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:42:46 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/06 10:05:32 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @brief Implementation of the ft_strdup function.
 */

#include <stdlib.h>

/**
 * @brief Duplicates a string by allocating memory for a new string.
 *
 * This function duplicates the null-terminated string 's' by allocating
 * memory for a new string and copying the characters from 's' to the newly
 * allocated memory.
 *
 * @param s A pointer to the null-terminated string to be duplicated.
 * @return A pointer to the newly allocated string, which is a duplicate of
 *         's'. Returns NULL in case of memory allocation failure.
 */
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
		ptr[i] = s[i];
	return (ptr);
}
