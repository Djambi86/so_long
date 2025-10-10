/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:25 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char str1[] = "I am goin insane";
	char str2[] = "I hope this works";
	char str3[] = "I am goin insane";
	char str4[] = "I hope this works"; 
	printf("Example: %s\nExample2: %s\n", str1, str2);

	memcpy(str1, str2, 5);
	printf("Original: %s %s\n", str1, str2);

	ft_memcpy(str3, str4, 5);
	printf("My Version: %s %s\n", str3, str4);

}*/
