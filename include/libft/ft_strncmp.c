/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:57 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main() 
{
    const char *str1 = "Depression";
    const char *str2 = "Deprodactyl";

    int result = ft_strncmp(str1, str2, 3);

    if (result < 0) 
    {
        printf("str1 is less than str2\n");
    } 
    else if (result > 0) 
    {
        printf("str1 is greater than str2\n");
    } 
    else 
    {
        printf("str1 is equal to str2 (first 3 characters)\n");
    }

    return 0;
}*/
