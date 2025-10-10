/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:28 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*--d = *--s;
		}
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char str1[] = "I cannot do it anymore";
	char str2[] = "Coding is so much fun (Sarcasm)";
	printf("Example: %s\nExample2: %s\n", str1, str2);

	memmove(str1, str2 + 2, 5);
	printf("Original: %s %s\n", str1, str2);

	ft_memmove(str1, str2 + 2, 5);
	printf("My version: %s %s\n", str1, str2);
}*/
