/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/06 19:23:45 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (n--)
	{
		*p++ = (unsigned char)c;
	}
	return (str);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Lets see if this works";
	char test[] = "Lets see if this works";
	printf("Example: %s\n", str);

	memset(str + 9, 'P', 8);
	printf("Original: %s\n", str);

	ft_memset(test + 9, 'P', 8);
    printf("New: %s\n", test);
}*/
