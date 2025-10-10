/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:05:58 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:54 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*the_new_string;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	the_new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!the_new_string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		the_new_string[i] = f(i, s[i]);
		i++;
	}
	the_new_string[i] = '\0';
	return (the_new_string);
}

/*#include <stdio.h>
#include <stdlib.h>

char my_func(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int main(void)
{
    const char *original = "hello world";
    char *result = ft_strmapi(original, my_func);

    if (result)
    {
        printf("Original: %s\n", original);
        printf("Mapped:   %s\n", result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
