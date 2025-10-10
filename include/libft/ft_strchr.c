/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/07 18:54:34 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*str == (char)chr)
			return ((char *)str);
		str++;
	}
	if ((char)chr == '\0')
		return ((char *)str);
	return (0);
}

/*#include <stdio.h>

int main(void)
{
    char text[] = "hello world";

    char *first = ft_strchr(text, 'o');
    char *last  = ft_strchr(text, 'o');
    char *none  = ft_strchr(text, 'x');
    char *nul   = ft_strchr(text, '\0');

    if (first)
    {
        int pos = first - text;
        printf("First 'o' at position %d\n", pos);
    }
    else
    {
        printf("Character 'o' not found\n");
    }

    if (last)
    {
        int pos = last - text;
        printf("Last 'o' at position %d\n", pos);
    }
    else
    {
        printf("Character 'o' not found\n");
    }

    if (!none)
    {
        printf("Character 'x' not found\n");
    }

    if (nul)
    {
        int pos = nul - text;
        printf("Null terminator at position %d\n", pos);
    }

    return 0;
}*/
