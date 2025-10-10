/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:13:00 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	i = 0;
	p = s;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int main() 
{
    const char data[] = "Hello, world!";
    char target = 'w';
    
    char *result = ft_memchr(data, target, sizeof(data));
    
    if (result != NULL) 
    {
        printf("Found '%c' at position: %ld\n", target, result - data);
    } 
    else 
    {
        printf("Character '%c' not found.\n", target);
    }
    
    return 0;
}*/
