/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:13:07 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main() 
{
    char a[] = "Hellp";
    char b[] = "Hellp";

    int result = ft_memcmp(a, b, 5);

    if (result < 0) 
    {
        printf("a is less than b\n");
    } 
    else if (result > 0) 
    {
        printf("a is greater than b\n");
    } 
    else 
    {
        printf("a is equal to b\n");
    }

    return 0;
}*/
