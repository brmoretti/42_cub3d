/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:48:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/06 09:54:11 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strndup.c
 * @brief Implementation of the ft_strndup function.
 */

#include "libft.h"

/**
 * @brief Creates a duplicate of a string up to a specified length.
 *
 * This function creates a new string that is a duplicate of the input
 * string `s`, up to a maximum length of `n` characters. If the length of `s`
 * is less than `n`,
 * the entire string is duplicated. The resulting string is null-terminated.
 *
 * @param s The input string to be duplicated.
 * @param n The maximum number of characters to be duplicated.
 * @return A pointer to the newly allocated duplicated string, or NULL if
 * the allocation fails.
 */
char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
		ptr[i] = s[i];
	return (ptr);
}
