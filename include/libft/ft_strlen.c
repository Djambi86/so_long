/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:39:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:51 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "Hello, world!";
	int len = ft_strlen(s);
    int original = strlen(s);

	printf("Length of \"%s\" is %d\n", s, len);
    printf("Length of \"%s\" is %d\n", s, original);
}*/
