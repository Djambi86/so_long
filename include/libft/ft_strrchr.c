/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/12 17:09:41 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

/*#include <stdio.h>

int main(void) 
{
    char *result1 = ft_strrchr("hello world", 'l');
    printf("Test 1 result: %s\n", result1);
    
    char *result2 = ft_strrchr("hello world", 'o');
    printf("Test 2 result: %s\n", result2);
    
    char *result3 = ft_strrchr("hello world", 'z');
    printf("Test 3 result: %s\n", result3);
    
    char *result4 = ft_strrchr("hello world", '\0');
    printf("Test 4 result: %s\n", result4);

    char *result5 = ft_strrchr("", 'a');
    printf("Test 5 result: %s\n", result5);
    return (0);
}*/
