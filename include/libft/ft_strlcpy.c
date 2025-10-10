/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:50 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	if (size > 0)
	{
		while (src[src_len] != '\0' && src_len < size - 1)
		{
			dst[src_len] = src[src_len];
			src_len++;
		}
		dst[src_len] = '\0';
	}
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}

/*#include <stdio.h>

int main(void)
{
    char buffer[10];
    size_t len = ft_strlcpy(buffer, "Hello, world!", sizeof(buffer));
    printf("Copied string: '%s'\n", buffer);   // Output: 'Hello, wo'
    printf("Length of source: %zu\n", len);    // Output: 13
}*/
