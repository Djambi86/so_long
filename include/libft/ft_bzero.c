/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:10:29 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) str;
	while (n > 0)
	{
		n = n - 1;
		*p++ = 0;
	}
}

/* #include <stdio.h>
#include <strings.h>
#include <unistd.h>

int main()
{
	char str[] = "This is a test";
	char test[] = "This is a test";
	printf("Example: %s\n", str);

	bzero(str, 5);
	write(1, "With unistd.h: ", 15);
	write(1, str, 10);
	write(1, "\n", 1);
	printf("Original: %s\n", str);

	ft_bzero(test, 5);
	printf("My Version: %s\n", test);
	
}*/
